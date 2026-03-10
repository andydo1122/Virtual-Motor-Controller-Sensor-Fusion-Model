//////////////////////////////////////////////
// IMU_Sim.cpp
// 
//////////////////////////////////////////////

#include "IMU_Sim.hpp"
#include "control/Complementary_Filter.hpp"
#include <cmath>
namespace Sensors
{
IMU_Sim::IMU_Sim() :
    angle(0.0),
    gyro(0.0),
    prev_angular_vel(0.0),
    accel(0.0),
    noise_generator(Noise::instance(0.01)),
    its_complementary_filter(&Control::Complementary_Filter::instance(0.5))
{
}

IMU_Sim& IMU_Sim::instance()
{
    static IMU_Sim instance;
    return instance;
}

void IMU_Sim::update(double p_angular_velocity, double p_dt)
{
    double angular_acceleration      = 0.0;
    double tangential_acceleration   = 0.0;
    double centripetal_acceleration = 0.0; 

    // Compute angular acceleration
    angular_acceleration     = (p_angular_velocity - prev_angular_vel) / p_dt;

    // Compute Tangential and centripetal acceleration
    tangential_acceleration  = IMU_RADIUS * angular_acceleration;
    centripetal_acceleration = IMU_RADIUS * pow(p_angular_velocity, 2); 

    // Compute Accelerometer - derived angle
    double accel_angle = std::atan2(tangential_acceleration + centripetal_acceleration,
        EARTH_GRAVITY);

    // Gyro reading
    gyro = p_angular_velocity + noise_generator.sample();
    
    // pass in gyro and angular accelerometer to update angle estimation 
    // Fuse Complementary Filter
    its_complementary_filter->update(accel_angle, gyro, p_dt);

    // Integrate angle 
    angle = its_complementary_filter->get_angle();
    
    // Compute Accelerometer reading
    accel = tangential_acceleration + centripetal_acceleration + EARTH_GRAVITY 
        + noise_generator.sample(); 

    // Store prev angular velocity
    prev_angular_vel = p_angular_velocity;
}

double IMU_Sim::get_angle() const
{
    return angle;
}

double IMU_Sim::get_gyro() const
{
    return gyro;
}

double IMU_Sim::get_accel() const
{
    return accel;
} 

} // namespace Sensors