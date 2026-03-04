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