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

static Motor_Model instance()
{
    Motor_Model instance;
    return instance;
}

void Motor_Model::apply_voltage(double p_voltage)
{
    voltage_input = p_voltage;
}

void Motor_Model::update(double p_dt)
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
    angular_velocity += accel * p_dt;
    angular_position += angular_velocity * p_dt;
}

double Motor_Model::get_velocity() const
{
    return angular_velocity;
}
    
double Motor_Model::get_position() const
{
    return angular_position;
}

} // namespace Motor