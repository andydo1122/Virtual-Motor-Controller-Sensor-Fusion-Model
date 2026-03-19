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

namespace Control
{
class Complementary_Filter; 
}

namespace Sensors
{
class IMU_Sim
{
public:
    // Constructor //
    IMU_Sim(double p_alpha); 
    IMU_Sim& operator=(const IMU_Sim&) = default;

    static IMU_Sim& instance(double p_alpha);

    // Procedures //

    // @param p_angle Theta
    // @param p_angular_velocity Omega (w) 
    // @param p_dt is Rate of time
    void update(double p_angle, double p_angular_velocity, double p_dt);
    
    // Getters //

    double get_angle() const;

    double get_gyro() const;

    double get_accel() const; 

    double get_accel_angle() const;

private:
    // Attributes // 
    static constexpr double IMU_RADIUS    = 0.05; // 5cm from shaft
    
    static constexpr double EARTH_GRAVITY = 9.81;
    
    double angle;
    
    double gyro;

    double prev_angular_vel;

    double radial;

    double tangential;

    // accelerometer
    double accel;
    
    double accel_angle;

    Noise noise_generator;

    // Associations //
    Control::Complementary_Filter* its_complementary_filter;

};
}

#endif // IMU_SIM_HPP

