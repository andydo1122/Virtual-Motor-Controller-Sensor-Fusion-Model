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

## 03/06/26: 

Currently, this is assuming that my IMU axis is aligned with gravity and gravity is positive along that axis. Need to later get:
- gravity prjection
- orientation matrix 
- and 3-axis accelerometer.

## 03/09/26:

Calculating 1-axis IMU rotating in a plane, the accelerometer angle is:

$\theta_{acc} = arctan2(a_t, a_g)$.

We'll need this since I'm integrating with my Complementary Filter for the IMU_Sim and I need to get the derived angular accelerometer.

Next step: need to give IMU_Sim to tune alpha (weight factor) for Complementary Filter. And finally test with the loop.

## 03/10/26: 

Since my accelerometer is using centripetal acceleration without dealing 3-axis rotations, my accelerometer angle is corrupted at higher speeds. For now, start with 30 and test results.

## 3/11/26:
Refining my tilt estimate, I would have to ignore the centripetal acceleration. This dates back to my formula that brought up on March 9th. The previous case back then was similar to rotating a horizontally.

## 3/17/26: Considering Accelerometer components on a rotating arm in a vertical plane
1. Radial (along the arm, pointing outward): 

    $a_r = -gcos(\theta) + rw^2$

    - $-gcos(\theta)$ is the gravity component along the arm.

2. Centripetal Acceleration: 

    $a_{c} = r \cdot w^2$.

3. Tangential (perpendicular to the arm, in the plane of rotation):

    $a_{tan}-gsin(\theta)+ra$

    - $-gsin(\theta)$ is the gravity component perpendicular to the arm. 

4. Tangential Acceleration:
    $a_{t} = r * a$ 

In addition, a 2-axis accelerometer in that plane would measure $(a_r, a_{tan})$

## Getting $\bold{angle}$ from these components 
I have to consider what my gravity is at.

If I had no motion, I would only have $a_r = -gcos(\theta)$ and $a_tan = -gsin(\theta)$

Thus, $\theta = atan2(-a_{tan}, -a_r)$

However with motion, the same formulas are contaminated by $rw^2$. But if I'm traveling at low speeds or acceleration, gravity dominates and I can still use the same formula above.

So $\theta_{acc} = atan2(-a_{tan}, -a_r)$ will end up as our true geometric model. Our angle is the orientation of the gravity vector in the sensor frame. 




