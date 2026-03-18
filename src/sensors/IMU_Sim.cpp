//////////////////////////////////////////////
// IMU_Sim.cpp
// 
//////////////////////////////////////////////

#include "IMU_Sim.hpp"
#include "control/Complementary_Filter.hpp"
#include <cmath>
namespace Sensors
{
IMU_Sim::IMU_Sim(double p_alpha) :
    angle(0.0),
    gyro(0.0),
    prev_angular_vel(0.0),
    accel(0.0),
    noise_generator(Noise::instance(0.01)),
    its_complementary_filter(&Control::Complementary_Filter::instance(p_alpha))
{
}

IMU_Sim& IMU_Sim::instance(double p_alpha)
{
    static IMU_Sim instance(p_alpha);
    return instance;
}

void IMU_Sim::update(double p_angle, double p_angular_velocity, double p_dt)
{
    double angular_acceleration      = 0.0; 
    double tangential_acceleration   = 0.0;
    double centripetal_acceleration  = 0.0; 
    double radial                    = 0.0;
    double tangential                = 0.0;

    // Compute angular acceleration
    angular_acceleration     = (p_angular_velocity - prev_angular_vel) / p_dt;

    // Compute Radial and tangential in arm frame
    radial     = -EARTH_GRAVITY* std::cos(p_angle) + IMU_RADIUS * pow(p_angular_velocity, 2);
    tangential = -EARTH_GRAVITY* std::sin(p_angle) + IMU_RADIUS * angular_acceleration;

    // Compute Tangential and centripetal acceleration
    tangential_acceleration  = IMU_RADIUS * angular_acceleration;
    centripetal_acceleration = IMU_RADIUS * pow(p_angular_velocity, 2); 

    // Compute Accelerometer reading (what the sensor would ouput)
    accel = tangential_acceleration 
        + centripetal_acceleration 
        + EARTH_GRAVITY 
        + noise_generator.sample(); 

    // For tilt estimation, remove centripetal acceleration
    // Compute Accelerometer - derived angle
    double accel_angle = std::atan2(tangential_acceleration,
        EARTH_GRAVITY);

    // Gyro reading
    gyro = p_angular_velocity + noise_generator.sample();
    
    // pass in gyro and angular accelerometer to update angle estimation 
    // Fuse Complementary Filter
    its_complementary_filter->update(accel_angle, gyro, p_dt);

    // Integrate angle 
    angle = its_complementary_filter->get_angle();

    // Store prev angular velocity
    prev_angular_vel = p_angular_velocity;
}

double IMU_Sim::get_angle() const
{
    // in radians
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