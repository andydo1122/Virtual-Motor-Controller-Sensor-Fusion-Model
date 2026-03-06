//////////////////////////////////////////////
// IMU_SIM_HPP
// A Inertial Measurement Unit
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

    static IMU_Sim& instance();

    // Procedures //
    void update(double p_angular_velocity, double p_dt);
    
    // Getters //
    double get_angle() const;
    double get_gyro() const;
    double get_accel() const; 

private:
    // Attributes // 
    static constexpr double IMU_RADIUS    = 0.05; // 5cm from shaft
    static constexpr double EARTH_GRAVITY = 9.81;
    double angle;
    double gyro;
    double prev_angular_vel;

    // accelerometer
    double accel;

    Noise noise_generator;  

};

}

#endif // IMU_SIM_HPP

