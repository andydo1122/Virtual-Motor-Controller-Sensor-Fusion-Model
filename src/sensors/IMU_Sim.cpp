//////////////////////////////////////////////
// IMU_Sim.cpp
// 
//////////////////////////////////////////////

#include "IMU_Sim.hpp"
#include <cmath>
namespace Sensors
{
IMU_Sim::IMU_Sim() :
    angle(0.0),
    gyro(0.0),
    prev_angular_vel(0.0),
    accel(0.0),
    noise_generator(Noise::instance(0.01))
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

    // Gyro reading
    gyro = p_angular_velocity + noise_generator.sample();
    
    // Integrate angle using dt
    angle += gyro * p_dt;
    
    // Accelerometer reading
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