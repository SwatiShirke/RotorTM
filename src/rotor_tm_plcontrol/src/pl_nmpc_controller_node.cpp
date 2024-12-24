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

#include "rotor_tm_msgs/msg/fm_command.hpp"
#include "rotor_tm_msgs/msg/PositionCommand.hpp"
#include "rotor_tm_msgs/msg/TrajCommand.hpp"


namespace nmpc_control_nodelet
{

  class NMPCControlNodelet : public rclpp::Node
  {
  public:
    NMPCControlNodelet(const rclcpp::NodeOptions &options)
    : Node("nmpc_control_nodelet", options),
    frame_id_("world"),
    set_pre_odom_quat_(false),
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


    clock_ = rclcpp::Clock();
    pre_odom_quat_ << 1.0, 0.0, 0.0, 0.0;

    //punlsihers
    //pub_ref_traj_ = this->create_publisher<nav_msgs::msg::Path>("reference_path", 1);
    //pub_pred_traj_ = this->create_publisher<rotor_tm_msgs::msg::TrajCommand>("predicted_path", 1);
    pub_FM_cmd_ = this->create_publisher<rotor_tm_msgs::msg::FMCommand>("pl_nmpc_FM_cmd",1);

    //subscribers
    sub_position_cmd_ = this->create_subscription<rotor_tm_msgs::msg::TrajCommand>(
      "des_traj_n", 1, std::bind(&NMPCControlNodelet::referenceCallback, this, std::placeholders::_1));

    sub_odometry_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "odom", 1, std::bind(&NMPCControlNodelet::odomCallback, this, std::placeholders::_1));
    }

  private:
  NMPCControl controller_;
  rclcpp::Clock clock_;
  double hover_thrust_;
  double mass_ = 0.0;
  double gravity_ = 9.81;
  double hover_thrust_ = mass_ * gravity_;
  // from odom callback
  std::string frame_id_;
  Eigen::Vector4d pre_odom_quat_;
  bool set_pre_odom_quat_;

  // ros functions
  void publishControl();
  void publishReference();
  void publishPrediction();
  void referenceCallback(const quadrotor_msgs::msg::PositionCommand::SharedPtr pos_cmd);
  void odomCallback(const nav_msgs::msg::Odometry::SharedPtr odom_msg);

  // rclcpp::Publisher<quadrotor_msgs::msg::TRPYCommand>::SharedPtr pub_trpy_cmd_;
  // rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr pub_ref_traj_;
  // rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr pub_pred_traj_;
  // rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr sub_odometry_;
  // rclcpp::Subscription<quadrotor_msgs::msg::PositionCommand>::SharedPtr sub_position_cmd_;
  // rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr sub_imu_;
  // rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr sub_motors_;
  // double thrustToRpm(const double thrust);  
 };

//ref callback
//Q: pre and post quaternions
//Q: if else 
void NMPCControlNodelet::referenceCallback(const rotor_tm_msgs::msg::TrajCommand::SharedPtr reference_msg )
{
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
  reference_states = Eigen::Matrix<double,kStateSize, kSamples>::Zeros();
  reference_inputs = Eigen::Matrix<double,kInputSize, kSamples>::Zeros();

  //declare variables used for reference inout calculations
  Eigen::VectorXd force_moments_null_vec = Eigen::VectorXd::Zero(9);
  Eigen::Vector3d ang_acc = Eigen::Vector3d::Zero();
  Eigen::Vector3d ang_vel = Eigen::Vector3d::Zero();
  Eigen::Vector3d moments = Eigen::Vector3d::Zero();

  //Q: where will we get force value from
  //Q: why is force_moments = 4d vetor it should be 6d vector
  // we have to make input vector 9d - F, M , V (null vector)

  if (filt_reference_msg->points.size() > 0)
  {
    auto iterator(filt_reference_msg->points.begin());
    for (int i=0; i < kSamples; i++)
    {
      reference_states.col(i) = iterator->position.x, iterator->position.y, iterator->position.z,
      iterator->quaternion.w, iterator->quaternion.x, iterator->quaternion.y, iterator->quaternion.z,
      iterator->velocity.x, iterator->velocity.y, iterator->velocity.z,
      iterator->angular_velocity.x, iterator->angular_velocity.y, iterator->angular_velocity.z;
      

      // ang_vel << iterator->angular_velocity.x, iterator->angular_velocity.y, iterator->angular_velocity.z;
      // ang_acc << iterator->angular_velocity_dot.x, iterator->angular_velocity_dot.y, iterator->angular_velocity_dot.z;
      // moments = inertia_matrix_ * ang_acc + ang_vel.cross(inertia_matrix_ * ang_vel);
      // force_moments << iterator->force, moments;
      // reference_inputs.col(i) = mixer_matrix_ * force_moments;
      // iterator++;
      z_force = mass_ * gravity_;
      force_moments_null_vec(2) =  z_force;
      reference_inputs.col(i) = force_moments_null_vec;
      iterator++;
    }

  }
  else
  {
    Eigen::Quaterniond q_heading;
    q_heading = Eigen::Quaterniond(Eigen::AngleAxisd(filt_reference_msg->yaw, Eigen::Matrix<double, 3, 1>::UnitZ()));
    Eigen::Vector4d state_q_heading_quat(pre_odom_quat_(0), pre_odom_quat_(1), pre_odom_quat_(2), pre_odom_quat_(3));
    Eigen::Vector4d current_q_heading_quat = Eigen::Vector4d(q_heading.w(), q_heading.x(), q_heading.y(), q_heading.z());

    if (current_q_heading_quat.dot(state_q_heading_quat) < 0)
    {
      q_heading.w() = -q_heading.w();
      q_heading.x() = -q_heading.x();
      q_heading.y() = -q_heading.y();
      q_heading.z() = -q_heading.z();
    }
    reference_states = (Eigen::Matrix<double, kStateSize, 1>() << filt_reference_msg->position.x,
                                                                  filt_reference_msg->position.y,
                                                                  filt_reference_msg->position.z,
                                                                  q_heading.w(), q_heading.x(),
                                                                  q_heading.y(), q_heading.z(),
                                                                  0.0, 0.0, 0.0,                                                                  
                                                                  0.0, 0.0, 0.0).finished().replicate(1, kSamples);
    reference_inputs = (Eigen::Matrix<double, kInputSize, 1>() << 0, 0, hover_thrust_,
                                                                  0, 0, 0,
                                                                  0, 0, 0).finished().replicate(1, kSamples);
  }
  controller_.setReferenceStates(reference_states);
  controller_.setReferenceInputs(reference_inputs);

  // run controller at reference frequency
  controller_.run();

  // publish control and predicted path
  publishControl();
  publishReference();
  publishPrediction();
}




//odom callback
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
  controller_.setState(state);
}
  

}// namespace nodelet ends here

