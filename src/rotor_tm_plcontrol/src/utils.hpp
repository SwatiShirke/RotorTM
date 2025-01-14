#ifndef LOAD_PARAMS_H
#define LOAD_PARAMS_H
#include <string>
#include "yaml-cpp/yaml.h" 

std::tuple<float, float, float> load_paramteters(std::string &file_path)
{   double mass;
    double intertia;
    double gravity;
    
    YAML::Node payload_params = YAML::LoadFile(file_path);
    mass = payload_params["mass"].as<double>();
    intertia = payload_params["intertia"].as<double>();
    gravity = payload_params["gravity"].as<double>();

    return std::make_tuple(mass, intertia, gravity);
    

}


#endif