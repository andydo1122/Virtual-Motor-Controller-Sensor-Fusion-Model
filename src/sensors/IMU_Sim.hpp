//////////////////////////////////////////////
// IMU_SIM_HPP
// Generating acceleration and gyro data.
// Helps with testing sensor fusion algorithms.
//////////////////////////////////////////////

#ifndef IMU_SIM_HPP
#define IMU_SIM_HPP

#include <iostream>
#include "Noise.hpp"

namespace Sensors
{
class IMU_Sim
{
public:
    // Constructor //
    IMU_Sim(); 
    IMU_Sim& operator=(const IMU_Sim&) = default;

    static IMU_Sim instance();

    // Procedures //
    void update(double p_angular_velocity);
    
    // Getters //
    double get_angle() const;
    double get_gyro() const;
    double get_accel() const; 

private:
    double angle;
    double gyro;
    double accel;
    // Noise noise_generator; // TODO: Implement later. 

};

}

#endif // IMU_SIM_HPP

