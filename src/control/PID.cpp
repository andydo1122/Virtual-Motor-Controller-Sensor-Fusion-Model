//////////////////////////////////////////////
// PID.cpp
//////////////////////////////////////////////

#include "PID.hpp"

namespace Control
{
PID::PID(double p_kp, double p_ki, double p_kd, 
    double p_output_min, double p_output_max) :
        kp(p_kp),
        ki(p_ki),
        kd(p_kd),
        integral(0.0),
        prev_error(0.0),
        output_min(p_output_min),
        output_max(p_output_max)
{

}

PID PID::instance(double p_kp, double p_ki, double p_kd, 
    double p_output_min, double p_output_max)
{
    static PID instance(p_kp, p_ki, p_kd, 
        p_output_min, p_output_max);

    return instance;
}

double PID::update(double p_error, double p_dt)
{
    // proportional
    double p = kp * p_error;

    // integral (tentative)
    double new_integral = integral + p_error * p_dt;
    double i = ki * new_integral;

    // derivative
    double d =  kd * (p_error - prev_error) / p_dt;

    // unsaturated output
    double output = p + i + d; 

    // Apply saturation
    double saturated_output = output;
    if(saturated_output > output_max)
    {
        saturated_output = output_max;
    }
    if(saturated_output < output_min)
    {
        saturated_output = output_min;
    }

    // anti-windup: only accept new integral if not saturated
    if(output == saturated_output)
    {
        integral = new_integral;
    }

    prev_error = p_error;

    return saturated_output;
}

void PID::reset()
{
    integral   = 0.0;
    prev_error = 0.0;
}


}