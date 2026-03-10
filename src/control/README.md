# PID (Proportional Integral Derivative controller)
Control mechanism, helps in maintaining desired output by continuously adjusting inputs based on error between current state and target state.

$K_p$ = proportional

$K_i$ = integral

$K_d$ = derivative

All three are tuning parameters.

Formula for PID controller output:

$Output = K_p \cdot error + K_i \cdot integral + K_d \cdot derivative$

## Think of this as the PID controlling speed.
And speed comes from our motor model and gyro.

SIDE NOTE: PID needs to eventually reset because too much accumated errors and slow down the system. When you want to use it? When your motor is at a different stage. For example, stopping -> running, or manual -> automatic. 

# Complementary filter
Plays a key role when simulating angle estimation, orientation drift correction, accelerometer and gyro fusion.

This all will be needed when I want to simulate a rotating IMU, gravity vector, tilt estimation, and attitude control.

In terms of definition, is used to estimate a variable by combining two or more measurements that have different noise characteristics. 

Simple Formula for Complementary filter online is expressed as:

$z = a \cdot x + (1 - a) \cdot y$

$a$ = weighting factor that determines the contribution of each sensor.


$x, y$ = Represents measurements of the same quantity from different sensors. in our case, gyro angle and accelerometer angle, respectively. 

$z$ = estimated angle

Another formula to follow what the code is following:


$\theta = a(\theta + w \cdot dt) + (1 - a) \theta_{acc}$

where:
$\theta$ = estimated angle

$w$ = gyro angular velocity

$\theta_{acc}$ = angle computed from accelerometer

$a$ = how much trust in gyro

$1 - a$ = how much trust in accelerometer.

## More on $a$, trust in gyro vs. accelerometer

$a$ close to 1.0 means more trust in gyro. Can be smooth, responsive, but drifts

$1 - a$ close to 0.0 means more trust in accelerometer. Can have no drift, but noisy. 

