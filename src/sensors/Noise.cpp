//////////////////////////////////////////////
// Noise.hpp
//////////////////////////////////////////////

#include "Noise.hpp"

namespace Sensors
{

Noise::Noise(double p_stddev) : 
    stddev(p_stddev),
    seed(1) 
{
}

double Noise::sample()
{
    // Simple uniform noise placeholder
    // Linear Congruential Generator 
    seed = (LCG_MULTIPLIER * seed + LCG_INCREMENT);

    double r = ((seed >> 16) & LCG_MOD_MASK) / LCG_NORMALIZER;

    // Shift to -1.0 -> +1.0 and then scale with standard deviation
    return (r - 0.5) * 2.0 * stddev;
}


} // namespace Sensors