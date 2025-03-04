#include "rotor_tm_plcontrol/nmpc_control.h"

namespace nmpc_control_nodelet
{

NMPCControl::NMPCControl()
  : current_state_(Eigen::Matrix<double, kStateSize, 1>::Zero()),
    reference_states_(Eigen::Matrix<double, kStateSize, kSamples>::Zero()),
    reference_inputs_(Eigen::Matrix<double, kInputSize, kSamples>::Zero()),
    predicted_states_(Eigen::Matrix<double, kStateSize, kSamples>::Zero()),
    predicted_inputs_(Eigen::Matrix<double, kInputSize, kSamples>::Zero()),
    solve_from_scratch_(true)
{
  // initialize quaternion w to 1
  current_state_(6) = 1.0;
  reference_states_.row(6).setOnes();
  predicted_states_.row(6).setOnes();
}

void NMPCControl::setState(const Eigen::Matrix<double, kStateSize, 1> &state) { current_state_.block(0, 0, 10, 1) = state.block(0, 0, 10, 1); }
void NMPCControl::setOmega(const Eigen::Matrix<double, 3, 1> &omega) { current_state_.block(10, 0, 3, 1) = omega; }
void NMPCControl::setReferenceStates(const Eigen::Matrix<double, kStateSize, kSamples> &reference_states) { reference_states_ = reference_states; }
void NMPCControl::setReferenceInputs(const Eigen::Matrix<double, kInputSize, kSamples> &reference_inputs) { reference_inputs_ = reference_inputs; }
void NMPCControl::setMass(double mass) { wrapper_.setMass(mass); }
void NMPCControl::setGravity(double gravity) { wrapper_.setGravity(gravity); }

Eigen::Matrix<double, kStateSize, 1> NMPCControl::getPredictedState() { return predicted_states_.col(1);  }
Eigen::Matrix<double, kInputSize, 1> NMPCControl::getPredictedInput() { return predicted_inputs_.col(0);  }
Eigen::Matrix<double, kStateSize, kSamples> NMPCControl::getPredictedStates() { return predicted_states_; }
Eigen::Matrix<double, kStateSize, kSamples> NMPCControl::getReferenceStates() { return reference_states_; }
Eigen::Matrix<double, kInputSize, kSamples> NMPCControl::getReferenceInputs() { return reference_inputs_; }

void NMPCControl::run()
{  wrapper_.setTrajectory(reference_states_, reference_inputs_);

    if (solve_from_scratch_)
  {
    // std::cout << "Solving NMPC with hover as initial guess.\n";
    wrapper_.prepare(current_state_);
    solve_from_scratch_ = false;
  }

  bool solved = wrapper_.update(current_state_);
  if (!solved)
    std::cout << "NMPC could not find a solution.";

  wrapper_.getStates(predicted_states_);
  wrapper_.getInputs(predicted_inputs_);
}

}