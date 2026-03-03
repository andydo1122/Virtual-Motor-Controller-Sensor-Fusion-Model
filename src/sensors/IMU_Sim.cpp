//////////////////////////////////////////////
// IMU_Sim.cpp
// 
//////////////////////////////////////////////

#include "IMU_Sim.hpp"
namespace Sensors
{
IMU_Sim::IMU_Sim() :
    angle(0.0),
    gyro(0.0),
    accel(0.0),
    noise_generator(Noise::instance(0.01))
{
}

IMU_Sim IMU_Sim::instance()
{
    static IMU_Sim instance;
    return instance;
}

void IMU_Sim::update(double p_angular_velocity)
{
    gyro = p_angular_velocity + noise_generator.sample();
    angle += gyro * 0.001; // Assume 1ms update
    accel = 0.0 + noise_generator.sample(); // placeholder, no real physics model yet
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