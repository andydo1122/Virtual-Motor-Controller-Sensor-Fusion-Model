# Virtual-Motor-Controller-Sensor-Fusion-Model

## 03/10/26
Test with main loop,
Results:
time=0 current speed= -0.00997497 fused angle= -9.77548e-06 voltage= 12

time=0.2 current speed= 17.7655 fused angle= 1.65721 voltage= 5.81257

time=0.4 current speed= 25.0333 fused angle= 2.40285 voltage= 2.69558

time=0.6 current speed= 27.9749 fused angle= 2.66152 voltage= 1.48424

time=0.8 current speed= 29.156 fused angle= 2.75944 voltage= 0.955993

time=1 current speed= 29.6341 fused angle= 2.79822 voltage= 0.836548

time=1.2 current speed= 29.8398 fused angle= 2.81372 voltage= 0.588793

time=1.4 current speed= 29.915 fused angle= 2.82002 voltage= 0.729249

time=1.6 current speed= 29.9568 fused angle= 2.82262 voltage= 0.632936

time=1.8 current speed= 29.973 fused angle= 2.8237 voltage= 0.572107

time=2 current speed= 29.9714 fused angle= 2.82417 voltage= 0.613448

time=2.2 current speed= 29.9727 fused angle= 2.82441 voltage= 0.592845

time=2.4 current speed= 29.978 fused angle= 2.82459 voltage= 0.478905

time=2.6 current speed= 29.9683 fused angle= 2.82461 voltage= 0.75605

time=2.8 current speed= 29.9775 fused angle= 2.8247 voltage= 0.529426

time=3 current speed= 29.9795 fused angle= 2.82475 voltage= 0.6499

time=3.2 current speed= 29.9876 fused angle= 2.82483 voltage= 0.593063

time=3.4 current speed= 29.9869 fused angle= 2.82489 voltage= 0.557327

time=3.6 current speed= 29.9766 fused angle= 2.82494 voltage= 0.657684

time=3.8 current speed= 29.9787 fused angle= 2.82496 voltage= 0.590211

time=4 current speed= 29.9745 fused angle= 2.82499 voltage= 0.673249

time=4.2 current speed= 29.991 fused angle= 2.82507 voltage= 0.541352

time=4.4 current speed= 29.9836 fused angle= 2.82504 voltage= 0.518391

time=4.6 current speed= 29.9893 fused angle= 2.82516 voltage= 0.622303

time=4.8 current speed= 29.9874 fused angle= 2.82521 voltage= 0.660257

A full closed-loop sensor fusion and control system. Here we can see that gyro rising toward the target speed. It also appears to be drifting slightly with gyro. Eventually, the speed is being slowly corrected by the accelerometer, remaining stable and smooth afterwards.

Currently, my simulation is like a bicycle wheel with an IMU taped to the rip.

## 3/17/26
Focus on making my model from a spinning wheel to a rotating arm.