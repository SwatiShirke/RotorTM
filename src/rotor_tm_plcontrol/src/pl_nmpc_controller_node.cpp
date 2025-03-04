#include <rotor_tm_plcontrol/nmpc_control.h>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <nav_msgs/msg/path.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/empty.hpp>
#include "rotor_tm_msgs/msg/fmn_command.hpp"
#include "rotor_tm_msgs/msg/position_command.hpp"
#include "rotor_tm_msgs/msg/traj_command.hpp"
//#include "utils.hpp"
namespace nmpc_control_nodelet
{

  class NMPCControlNodelet : public rclcpp::Node
  {
  public:
    NMPCControlNodelet(const rclcpp::NodeOptions &options)
    : Node("nmpc_control_nodelet", options),
    frame_id_("simulator"),
    set_pre_odom_quat_(false)
    {
    // this->declare_parameter("mass", 0.0);
    // this->declare_parameter("gravity", 0.0);

    // if (!this->get_parameter("mass", mass_)) {
    //     RCLCPP_ERROR(this->get_logger(), "[NMPC] No mass!");
    // } else {
    //     RCLCPP_INFO(this->get_logger(), "[NMPC] mass: %.4f", mass_);
    // }
    // if (!this->get_parameter("gravity", gravity_)) {
    //     RCLCPP_ERROR(this->get_logger(), "[NMPC] No gravity!");
    // } else {
    //     RCLCPP_INFO(this->get_logger(), "[NMPC] gravity: %.4f", gravity_);
    // }

    // std::string config_file_path;
    // //std::tuple<float, float, float> val_tuple;
    // this->declare_parameter<std::string>("config_file", "");
    // this->get_parameter("config_file", config_file_path);
    // if (!config_file_path.empty())
    // {
    //   RCLCPP_INFO(this->get_logger(), "reading Payload parameter file");
    //   auto [mass, intertia, gravity]  = load_paramteres(config_file_path);
    // }
    // else
    // {
    //   RCLCPP_INFO(this->get_logger(), "can not read yaml file");
    // }

    clock_ = rclcpp::Clock();
    pre_odom_quat_ << 1.0, 0.0, 0.0, 0.0;
    
    //set qos
    auto qos_profile_ = this->create_custom_qos();
    //punlsihers
    pub_FMN_cmd_ = this->create_publisher<rotor_tm_msgs::msg::FMNCommand>("/payload/pl_nmpc_FMN_cmd",qos_profile_);
    pub_ref_traj_ = this->create_publisher<nav_msgs::msg::Path>("/payload/reference_path", 1);
    pub_pred_traj_ = this->create_publisher<nav_msgs::msg::Path>("/payload/predicted_path", 1);   

    //subscribers    
    
    sub_traj_cmd_ = this->create_subscription<rotor_tm_msgs::msg::TrajCommand>(
      "/payload/des_traj_n", qos_profile_, std::bind(&NMPCControlNodelet::referenceCallback, this, std::placeholders::_1));
    sub_odometry_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "/payload/odom", qos_profile_, std::bind(&NMPCControlNodelet::odomCallback, this, std::placeholders::_1));
    }

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  
  private:
    NMPCControl controller_;
    rclcpp::Clock clock_;
    double mass_ = 0.278;
    double gravity_ = 9.81;
    double hover_thrust_ = mass_ * gravity_;
    //double Eigen::Matrix<double, 3, 3> inertia_matrix_
    Eigen::Matrix<double, 3,3> mass_matrix_ = mass_ * Eigen::MatrixXd::Identity(3,3);
     
    // from odom callback
    std::string frame_id_;
    Eigen::Vector4d pre_odom_quat_;
    bool set_pre_odom_quat_;
    Eigen::Matrix<double,kStateSize, 1> pl_current_state; 

    // ros functions
    Eigen::Matrix<double,kStateSize, 1> get_pl_current_state();
    void publishControl();
    void publishReference();
    void publishPrediction();
    void referenceCallback(const rotor_tm_msgs::msg::TrajCommand::SharedPtr reference_msg);
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr odom_msg);
    rclcpp::QoS create_custom_qos();
    rclcpp::Publisher<rotor_tm_msgs::msg::FMNCommand>::SharedPtr pub_FMN_cmd_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr pub_ref_traj_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr pub_pred_traj_;       
    
    rclcpp::Subscription<rotor_tm_msgs::msg::TrajCommand>::SharedPtr sub_traj_cmd_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr sub_odometry_;
    //rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr sub_imu_;
    
 };


//class functions
Eigen::Matrix<double,kStateSize, 1> NMPCControlNodelet::get_pl_current_state()
{
  return this->pl_current_state;
}

rclcpp::QoS NMPCControlNodelet::create_custom_qos() {
            // Use the correct type for the history policy
            auto history_policy = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
            size_t depth = 1;

            // Create QoSInitialization with the correct arguments
            rclcpp::QoSInitialization qos_init(history_policy, depth);

            // Create QoS profile and set additional parameters
            rclcpp::QoS qos_profile(qos_init);
            qos_profile.reliability(rclcpp::ReliabilityPolicy::BestEffort);
            qos_profile.durability(rclcpp::DurabilityPolicy::Volatile);

            return qos_profile;
    }

void NMPCControlNodelet::referenceCallback(const rotor_tm_msgs::msg::TrajCommand::SharedPtr reference_msg )
{ 
  //std::cout<<"breakpoint 3"<<'\n';
  // for ( auto point : reference_msg->points)
  // {
  //   std::cout<<point.position.x<<'\n';
  // }
  rotor_tm_msgs::msg::TrajCommand::SharedPtr filt_reference_msg(reference_msg);
  Eigen::Vector4d pre_quat(pre_odom_quat_(0), pre_odom_quat_(1), pre_odom_quat_(2), pre_odom_quat_(3));
  Eigen::Vector4d current_quat;

  for (auto point : filt_reference_msg->points)
  {
    current_quat = Eigen::Vector4d(point.quaternion.w, point.quaternion.x, point.quaternion.y, point.quaternion.z);
    if (current_quat.dot(pre_quat) < 0)
    {
      point.quaternion.w = -point.quaternion.w;
      point.quaternion.x = -point.quaternion.x;
      point.quaternion.y = -point.quaternion.y;
      point.quaternion.z = -point.quaternion.z;
      current_quat = -current_quat;
    }
    pre_quat = current_quat;
  }

  //initialize ref state and input variables
  Eigen::Matrix<double,kStateSize, kSamples> reference_states;
  Eigen::Matrix<double, kInputSize, kSamples> reference_inputs;
  reference_states = Eigen::Matrix<double,kStateSize, kSamples>::Zero();
  reference_inputs = Eigen::Matrix<double,kInputSize, kSamples>::Zero();

  //declare variables used for reference inout calculations
  Eigen::VectorXd force_moments_null_vec = Eigen::VectorXd::Zero(9);
  Eigen::Vector3d ang_acc = Eigen::Vector3d::Zero();
  Eigen::Vector3d ang_vel = Eigen::Vector3d::Zero();
  Eigen::Vector3d lin_acc = Eigen::Vector3d::Zero();
  Eigen::Vector3d lin_vel = Eigen::Vector3d::Zero();
  Eigen::Vector3d moments = Eigen::Vector3d::Zero();
  Eigen::Vector3d force = Eigen::Vector3d::Zero();
  Eigen::Vector3d e3_vector = Eigen::Vector3d::Zero();
  e3_vector << 0.0,0,1;
  
  
  
  if (filt_reference_msg->points.size() > 1)
  {
    auto iterator(filt_reference_msg->points.begin());
    for (int i=0; i < kSamples; i++)
    { 
      
      
      reference_states.col(i) << iterator->position.x, iterator->position.y, iterator->position.z,
      iterator->velocity.x, iterator->velocity.y, iterator->velocity.z,
      iterator->quaternion.w, iterator->quaternion.x, iterator->quaternion.y, iterator->quaternion.z,
      iterator->angular_velocity.x, iterator->angular_velocity.y, iterator->angular_velocity.z;
      

      // ang_vel << iterator->angular_velocity.x, iterator->angular_velocity.y, iterator->angular_velocity.z;
      lin_acc << iterator->acceleration.x, iterator->acceleration.y, iterator->acceleration.z;
      
      // moments = inertia_matrix_ * ang_acc + ang_vel.cross(inertia_matrix_ * ang_vel);
      // force_moments << iterator->force, moments;
      // reference_inputs.col(i) = mixer_matrix_ * force_moments;
      // iterator++;
       
      //double z_force = mass_ * gravity_;
      // force_moments_null_vec(2) =  hover_thrust_;
      // reference_inputs.col(i) = force_moments_null_vec;
      
      //std::cout << "lin_acc" << lin_acc << '\n';
      force =  mass_matrix_ * lin_acc + hover_thrust_ * e3_vector;  //
      //std::cout << "ref_force " << force << '\n';

      // std::cout << "ref forces" << '\n';
      // std::cout << force << '\n';
      reference_inputs.col(i) << force , 0,0,0,0,0,0;
      iterator++;
    }
  }
  else if(filt_reference_msg->points.size() == 1)
  { 
    //std::cout << "one msg recieved"<< '\n';
    // Eigen::Quaterniond q_heading;
    // q_heading = Eigen::Quaterniond(Eigen::AngleAxisd(filt_reference_msg->yaw, Eigen::Matrix<double, 3, 1>::UnitZ()));
    // Eigen::Vector4d state_q_heading_quat(pre_odom_quat_(0), pre_odom_quat_(1), pre_odom_quat_(2), pre_odom_quat_(3));
    // Eigen::Vector4d current_q_heading_quat = Eigen::Vector4d(q_heading.w(), q_heading.x(), q_heading.y(), q_heading.z());

    // if (current_q_heading_quat.dot(state_q_heading_quat) < 0)
    // {
    //   q_heading.w() = -q_heading.w();
    //   q_heading.x() = -q_heading.x();
    //   q_heading.y() = -q_heading.y();
    //   q_heading.z() = -q_heading.z();
    // }

    // reference_states = (Eigen::Matrix<double, kStateSize, 1>() << filt_reference_msg->position.x,
    //                                                               filt_reference_msg->position.y,
    //                                                               filt_reference_msg->position.z,
    //                                                               q_heading.w(), q_heading.x(),
    //                                                               q_heading.y(), q_heading.z(),
    //                                                               0.0, 0.0, 0.0,                                                                  
    //                                                               0.0, 0.0, 0.0).finished().replicate(1, kSamples);
    
 

    reference_states = (Eigen::Matrix<double, kStateSize, 1>() << filt_reference_msg->points[0].position.x,
                                                                  filt_reference_msg->points[0].position.y,
                                                                  filt_reference_msg->points[0].position.z,
                                                                  0, 0, 0,
                                                                  1, 0, 0, 0,                                                                 
                                                                  0.0, 0.0, 0.0).finished().replicate(1, kSamples);
    
    
    reference_inputs = (Eigen::Matrix<double, kInputSize, 1>() << 0, 0, hover_thrust_,
                                                                  0, 0, 0,
                                                                 0, 0, 0).finished().replicate(1, kSamples);
     
    
    }
  
  else 
  {
    Eigen::Matrix<double, kStateSize, 1> state = this->get_pl_current_state();
    for (int i=0; i < kSamples; i++)
    {       
      reference_states.col(i) = state;
      //std::cout << "x :" <<state(0) << "y :" << state(1) << "z :" << state(2)<< '\n'; 
      reference_inputs.col(i) << 0, 0, hover_thrust_,
                                 0, 0, 0,
                                 0, 0, 0;
    }
  }


  controller_.setReferenceStates(reference_states);
  controller_.setReferenceInputs(reference_inputs);   
  controller_.run();

  // publish control and predicted path
  publishControl();
  publishReference();
  publishPrediction();
}

void NMPCControlNodelet::odomCallback(const nav_msgs::msg::Odometry::SharedPtr odom_msg)
{
  Eigen::Matrix<double, kStateSize, 1> state;
  frame_id_ = odom_msg->header.frame_id;
  state(0) = odom_msg->pose.pose.position.x;
  state(1) = odom_msg->pose.pose.position.y;
  state(2) = odom_msg->pose.pose.position.z;
  state(3) = odom_msg->twist.twist.linear.x;
  state(4) = odom_msg->twist.twist.linear.y;
  state(5) = odom_msg->twist.twist.linear.z;
  Eigen::Vector4d current_odom_quat(odom_msg->pose.pose.orientation.w, odom_msg->pose.pose.orientation.x,
                                    odom_msg->pose.pose.orientation.y, odom_msg->pose.pose.orientation.z);

  // set initial quaternion from odometry
  if (not set_pre_odom_quat_)
  {
    pre_odom_quat_ = current_odom_quat;
    set_pre_odom_quat_ = true;
  }

  if (current_odom_quat.dot(pre_odom_quat_) < 0)
  {
    state(6) = -odom_msg->pose.pose.orientation.w;
    state(7) = -odom_msg->pose.pose.orientation.x;
    state(8) = -odom_msg->pose.pose.orientation.y;
    state(9) = -odom_msg->pose.pose.orientation.z;
    pre_odom_quat_ = -current_odom_quat;
  }
  else
  {
    state(6) = odom_msg->pose.pose.orientation.w;
    state(7) = odom_msg->pose.pose.orientation.x;
    state(8) = odom_msg->pose.pose.orientation.y;
    state(9) = odom_msg->pose.pose.orientation.z;
    pre_odom_quat_ = current_odom_quat;
  }
  this->pl_current_state = state;
  // std::cout << "state" << '\n';
  // std::cout << state << '\n';
  controller_.setState(state);
}
  
void NMPCControlNodelet::publishControl()
{
  
  Eigen::Matrix<double, kInputSize, 1> pred_input = controller_.getPredictedInput();
  rotor_tm_msgs::msg::FMNCommand fmn_msg;
  fmn_msg.header.stamp = clock_.now();
  fmn_msg.header.frame_id = frame_id_;
  fmn_msg.rlink_thrust.x = pred_input(0);
  fmn_msg.rlink_thrust.y = pred_input(1);
  fmn_msg.rlink_thrust.z = pred_input(2);
  fmn_msg.moments.x = pred_input(3);
  fmn_msg.moments.y = pred_input(4);
  fmn_msg.moments.z = pred_input(5);
  fmn_msg.null_space_vec.x = pred_input(6);
  fmn_msg.null_space_vec.y = pred_input(7);
  fmn_msg.null_space_vec.z = pred_input(8);
  pub_FMN_cmd_->publish(fmn_msg);

}

void NMPCControlNodelet::publishReference()
{
  Eigen::Matrix<double, kStateSize, kSamples> reference_states = controller_.getReferenceStates();  
  nav_msgs::msg::Path path_msg;
  path_msg.header.stamp = clock_.now();
  path_msg.header.frame_id = frame_id_;
  geometry_msgs::msg::PoseStamped pose;
  for (int i=0; i < kSamples; i++)
  { 
    pose.header.stamp = clock_.now();
    pose.header.frame_id = frame_id_;
    pose.pose.position.x = reference_states(0,i);
    pose.pose.position.y = reference_states(1, i);
    pose.pose.position.z = reference_states(2, i);
    pose.pose.orientation.w = reference_states(6, i);
    pose.pose.orientation.x = reference_states(7, i);
    pose.pose.orientation.y = reference_states(8, i);
    pose.pose.orientation.z = reference_states(9, i);
    path_msg.poses.push_back(pose);    
  }

  pub_ref_traj_->publish(path_msg);
}

void NMPCControlNodelet::publishPrediction()
{
  Eigen::Matrix<double, kStateSize, kSamples> reference_states = controller_.getPredictedStates();
  nav_msgs::msg::Path path_msg;
  path_msg.header.stamp = clock_.now();
  path_msg.header.frame_id = frame_id_;
  geometry_msgs::msg::PoseStamped pose;
  for (int i=0; i < kSamples; i++)
  { 
    pose.header.stamp = clock_.now();
    pose.header.frame_id = frame_id_;
    pose.pose.position.x = reference_states(0,i);
    pose.pose.position.y = reference_states(1, i);
    pose.pose.position.z = reference_states(2, i);
    pose.pose.orientation.w = reference_states(6, i);
    pose.pose.orientation.x = reference_states(7, i);
    pose.pose.orientation.y = reference_states(8, i);
    pose.pose.orientation.z = reference_states(9, i);
    path_msg.poses.push_back(pose);    
  }
  pub_pred_traj_->publish(path_msg);
}


}// namespace nodelet ends here

RCLCPP_COMPONENTS_REGISTER_NODE(nmpc_control_nodelet::NMPCControlNodelet)

int main(int argc, char *argv[])
{ 
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<nmpc_control_nodelet::NMPCControlNodelet>(rclcpp::NodeOptions())); 
  rclcpp::shutdown();
  return 0;
}