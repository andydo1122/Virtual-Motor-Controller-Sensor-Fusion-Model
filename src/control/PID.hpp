//////////////////////////////////////////////
// PID.hpp
// Proportional Integral Derivative
// Control mechanism that helps main desired output.
//////////////////////////////////////////////

#ifndef PID_HPP
#define PID_HPP

#include <iostream>

namespace Control
{
class PID
{
public:
    // Constructor //
    PID(double p_kp, double p_ki, double p_kd,
        double p_output_min, double p_output_max);
    PID& operator=(const PID&) = default;

    static PID& instance(double p_kp, double p_ki, double p_kd, 
        double p_output_min, double p_output_max);

    // Procedures //
    double update(double p_error, double p_dt);
    void reset();


private:
    // Attributes //
    double kp;
    double ki;
    double kd;
    double integral;
    double prev_error;
    double output_min;
    double output_max;

};


} // namespace Control

#endif