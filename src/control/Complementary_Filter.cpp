////////////////////////////////////////////////
// Complementary_Filter.cpp
//////////////////////////////////////////////

#include "Complementary_Filter.hpp"

namespace Control
{
Complementary_Filter::Complementary_Filter(double p_alpha) :
    alpha(p_alpha),
    angle(0.0)
{
}

Complementary_Filter& Complementary_Filter::instance(double p_alpha)
{
    static Complementary_Filter instance(p_alpha);
    return instance; 
}

double Complementary_Filter::update(double p_accel_angle, double p_gyro_rate, double p_dt)
{
    double gyro_angle = angle + p_gyro_rate * p_dt;
    angle = alpha * gyro_angle + (1.0 - alpha) * p_accel_angle;

    return angle;
}

} // namespace Control