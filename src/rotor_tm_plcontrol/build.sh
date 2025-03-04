#!/bin/bash
echo ""
echo "building payload nmpc"
cd ../..
colcon build --packages-select rotor_tm_config
source install/setup.bash


#read paths from main config file
cd src/rotor_tm_config/config
config_file="main_config.yaml"  
payload_params_path=$(yq e '.config_paths.payload_params_path' $config_file)
uav_params_path=$(yq e '.config_paths.uav_params_path' $config_file) 
mechanism_params_path=$(yq e '.config_paths.mechanism_params_path' $config_file)
payload_control_gain_path=$(yq e '.config_paths.payload_control_gain_path' $config_file)
uav_control_gain_path=$(yq e '.config_paths.uav_control_gain_path' $config_file)
nmpc_filename=$(yq e '.config_paths.nmpc_filename' $config_file)


cd ../..
cd rotor_tm_plcontrol
source ~/acados/mpcenv/bin/activate 

cd scripts
python3 payload_controller.py $payload_params_path $uav_params_path $mechanism_params_path $payload_control_gain_path $uav_control_gain_path $nmpc_filename

cd ..
cp scripts/c_generated_code/payload_model_model/payload_model_model.h include/rotor_tm_plcontrol
cp scripts/c_generated_code/acados_solver_payload_model.h include/rotor_tm_plcontrol

cd ../.. 
colcon build --packages-select rotor_tm_plcontrol
source install/setup.bash 



