#!/bin/bash
echo ""
echo "building payload nmpc"
cd ../..
colcon build --packages-select rotor_tm_config
source install/setup.bash

cd src/rotor_tm_plcontrol
source ~/acados/mpcenv/bin/activate
cd scripts
python3 payload_controller.py 

cd ..
cp scripts/c_generated_code/payload_model_model/payload_model_model.h include/rotor_tm_plcontrol
cp scripts/c_generated_code/acados_solver_payload_model.h include/rotor_tm_plcontrol

cd ../.. 
colcon build --packages-select rotor_tm_plcontrol
source install/setup.bash



