//////////////////////////////////////////////
// MotorModel.cpp
// 
//////////////////////////////////////////////

#include "Motor_Model.hpp"
#include "Motor_Params.hpp"
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

    // Torque Physics //
    // K_e(w)
    double back_emf = MOTOR_KE * angular_velocity;

    // i
    double current = (voltage_input - back_emf) / MOTOR_RESISTANCE;

    // t
    double torque = MOTOR_KT * current;

    // t_load
    double load_torque = 0.0; // TODO, expand function later on.

    // Equation of derivative of angular velocity (w) with respect to time (t) [dw/dt]
    // Mechanical
    // dw / dt
    double accel = (torque - MOTOR_FRICTION * angular_velocity - load_torque)/MOTOR_INERTIA; 
    // Torque Physics //
    
    // Update
    angular_velocity += accel * dt;
    angular_position += angular_velocity * dt;
}

} // namespace Motor