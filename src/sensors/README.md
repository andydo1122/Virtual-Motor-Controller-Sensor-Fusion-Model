# Virtual Motor Controller Sensor Fusion Module

## Using LCG (Linear Congruential Generator) for Noise file

Forumal LCG follows:

$seed_{n+1} = (a \cdot seed_n + c) \bmod m $

Where:

$a$ -> multiplier

$c$ -> increment

$m$ -> modulus

## Constants 

Reason for using 214013 and 2531011 initially:

These numbers come from Microsoft Vigual C++ runtime's rand() implementation. LCG pairs. 

For 32767: This is the maximum value of 15 bit integer. Allows LCG to extract 15 bits of randomness from the seed. Dividing with this number also normalizes random value into range : 0.0 -> 1.0

## Improvements for later...
- Use Gaussian Nosie
- Bias dift
- Axis misalignment

## Improving Accelerometer
Eventually, we can advance the accelerometer to use equation:

$a = r \cdot a` + r \cdot w^{2}$

where:

$a$ = linear acceleration

$r$ = distance from rotation axis

$a`$ = angular acceleration

$w$ = angular velocity

We'll need the core accelerometer physics firsts, thus we'll need Tangential Acceleration : 

$a_{t} = r * a$ 

where $r$ is distance from rotation axis to IMU. While $a$ is angular acceleration (change in angular velocity)

We'll also need centripetal acceleration: 

$a_{c} = r \cdot w^2$. 

Always directed toward center of rotation.

Gravity projection is needed:

$a_{g} = g \cdot$ (projection onto IMU axis).

Combining them all:

$a_{true} = a_t + a_c + a_g$

Gives meaningful signal for our complementary filter. 

03/06/26: Currently, this assuming that my IMU axis is aligned with gravity and gravity is positive along that axis. Need to later get an actual gravity prjection, orientation matrix, and 3-axis accelerometer.




