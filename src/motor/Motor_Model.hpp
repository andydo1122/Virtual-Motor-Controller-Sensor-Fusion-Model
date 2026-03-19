//////////////////////////////////////////////
// Motor_Model.hpp
// The motor model will simulate torque and angular acceleration.
// This integrates our velocity and position and test control loops
// without hardware.
// Considered the "plant" in control theory terms.
// Helps in simulating a DC motor's physics so that our ocntroller
// has something "real" to control. 
//////////////////////////////////////////////

#ifndef MOTOR_MODEL_HPP
#define MOTOR_MODEL_HPP

#include <iostream>
#include "Motor_Model.hpp"
namespace Motor
{
class Motor_Model
{
public:
    // Constructor //
    Motor_Model();
    Motor_Model& operator=(const Motor_Model&) = default; 

    static Motor_Model& instance(); 

    // Procedures //

    // @param p_dt delta time
    void update(double p_dt);

    // @param p_voltage Given voltage
    void apply_voltage(double p_voltage);

    // Getters //
    double get_angular_velocity() const;

    double get_angle_position() const;

private:
    double voltage_input;
    
    double angular_velocity;

    // If angle is positive, it is rotating counter 
    // clockwise in a vertical plane.
    double angular_position; // radians, 0 will mean the arm is straight down.  
};

} // namespace Motor

#endif // MOTOR_MODEL_HPP