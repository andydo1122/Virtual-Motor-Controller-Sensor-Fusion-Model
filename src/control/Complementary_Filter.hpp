//////////////////////////////////////////////
// Complementary_Filter.hpp
// Produces stable angle estimates,
// Fusing gyro + accelerometer 
//////////////////////////////////////////////

#ifndef COMPLEMENTARY_FILTER_HPP
#define COMPLEMENTARY_FILTER_HPP

#include <iostream>

namespace Control
{
class Complementary_Filter
{
public:
    // Constructor //
    explicit Complementary_Filter(double p_alpha);
    Complementary_Filter& operator=(const Complementary_Filter&) = default;

    static Complementary_Filter& instance(double p_alpha);

    // Procedures //
    void update(double p_accel_angle, double p_gyro_rate, double p_dt);

    // Reset our angle.
    void reset();
    
    // Getters //
    double get_angle() const;

private:
    double alpha;
    double angle;

};

} // namespace Control

#endif