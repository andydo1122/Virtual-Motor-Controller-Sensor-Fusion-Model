////////////////////////////////////////////////
// Complementary_Filter.cpp
//////////////////////////////////////////////

#include "Complementary_Filter.hpp"
#include <algorithm>

namespace Control
{
Complementary_Filter::Complementary_Filter(double p_alpha) :
    angle(0.0)
{
    alpha = std::clamp(p_alpha, 0.0, 1.0);
}

Complementary_Filter& Complementary_Filter::instance(double p_alpha)
{
    static Complementary_Filter instance(p_alpha);
    return instance; 
}

void Complementary_Filter::update(double p_accel_angle, double p_gyro_rate, double p_dt)
{
    double gyro_angle = angle + p_gyro_rate * p_dt;
    angle = alpha * gyro_angle + (1.0 - alpha) * p_accel_angle;
}

void Complementary_Filter::reset()
{
    angle = 0.0;
}

double Complementary_Filter::get_angle() const
{
    return angle;
}

} // namespace Control