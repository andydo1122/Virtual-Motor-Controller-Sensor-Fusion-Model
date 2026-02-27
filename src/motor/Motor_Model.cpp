//////////////////////////////////////////////
// MotorModel.cpp
// 
//////////////////////////////////////////////

#include "Motor_Model.hpp"
namespace Motor
{
Motor_Model::Motor_Model() :
    voltage_input(0.0),
    angular_velocity(0.0),
    angular_position(0.0)
{

}

void Motor_Model::apply_voltage(double voltage)
{
    voltage_input = voltage;
}

void Motor_Model::update(double dt)
{

    double accel     =  0.0; // TODO: implement physics
    angular_velocity += accel * dt;
    angular_position += angular_velocity * dt;
}

} // namespace Motor