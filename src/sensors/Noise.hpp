
//////////////////////////////////////////////
// Noise.hpp
// Sample of Noise or generated data
// to feed.
//////////////////////////////////////////////

#ifndef NOISE_HPP
#define NOISE_HPP


namespace Sensors
{

class Noise
{
public:
    // Constructor //
    explicit Noise(double p_stddev);
    Noise& operator=(const Noise&) = default;

    static Noise instance();

    // Procedures //
    double sample();

private:
    static constexpr unsigned int LCG_MULTIPLIER = 214013;
    static constexpr unsigned int LCG_INCREMENT  = 2531011;
    static constexpr unsigned int LCG_MOD_MASK   = 0x7FFF;  // 32767
    static constexpr double       LCG_NORMALIZER = 32767.0; 

    // Attributes //
    double stddev;
    unsigned int seed; 

};

} // namespace Sensors

#endif