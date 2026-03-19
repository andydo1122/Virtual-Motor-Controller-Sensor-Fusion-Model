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

Currently, my simulation is like a bicycle wheel with an IMU taped to the rim.

## 3/17/26
Focus on making my model from a spinning wheel to a rotating arm.

## 3/18/26
Currently my closed-loop is a simulation of a Direct Current motor driving a rotating arm with an IMU wrapped on the arm; thus, feeding to a complementary filter and producing a fused angle estimate.

time=0 angle=0 Acelerometer angle=-3.14159 current speed= 0.00127171 fused angle= -0.0628306 voltage= 12

time=0.2 angle=0.699697 Acelerometer angle=2.38273 current speed= 6.02202 fused angle= 2.389 voltage= 1.94097

time=0.4 angle=2.17903 Acelerometer angle=0.698767 current speed= 8.41372 fused angle= 1.45017 voltage= 0.902789

time=0.6 angle=3.97292 Acelerometer angle=-0.591607 current speed= 9.38702 fused angle= 0.174461 voltage= 0.483698

time=0.8 angle=5.89363 Acelerometer angle=-2.42021 current speed= 9.7584 fused angle= -1.37468 voltage= 0.314521

time=1 angle=7.86538 Acelerometer angle=1.09542 current speed= 9.9226 fused angle= 1.83327 voltage= 0.246228

time=1.2 angle=9.85758 Acelerometer angle=-0.288559 current speed= 9.98865 fused angle= 0.52664 voltage= 0.21866

time=1.4 angle=11.8579 Acelerometer angle=-1.93538 current speed= 10.0148 fused angle= -0.964101 voltage= 0.207531

time=1.6 angle=13.8614 Acelerometer angle=1.32679 current speed= 10.0307 fused 
angle= 1.94506 voltage= 0.203039

time=1.8 angle=15.866 Acelerometer angle=-0.104558 current speed= 10.0296 fused angle= 0.713653 voltage= 0.201225

time=2 angle=17.8709 Acelerometer angle=-1.62607 current speed= 10.0289 fused angle= -0.712918 voltage= 0.200493

time=2.2 angle=19.8758 Acelerometer angle=1.5776 current speed= 10.0263 fused angle= 1.95693 voltage= 0.200198

time=2.4 angle=21.8807 Acelerometer angle=0.0730959 current speed= 10.0332 fused angle= 0.892739 voltage= 0.200079

time=2.6 angle=23.8853 Acelerometer angle=-1.36873 current speed= 10.0277 fused angle= -0.492934 voltage= 0.200031

time=2.8 angle=25.8898 Acelerometer angle=1.87402 current speed= 10.0278 fused angle= 1.78233 voltage= 0.200011

time=3 angle=27.8942 Acelerometer angle=0.252135 current speed= 10.0235 fused angle= 1.07338 voltage= 0.200004

time=3.2 angle=29.8983 Acelerometer angle=-1.14028 current speed= 10.0294 fused angle= -0.288411 voltage= 0.200001

time=3.4 angle=31.9023 Acelerometer angle=2.24337 current speed= 10.0175 fused angle= 1.24797 voltage= 0.199999

time=3.6 angle=33.9062 Acelerometer angle=0.434354 current speed= 10.0095 fused angle= 1.25595 voltage= 0.199999

time=3.8 angle=35.9099 Acelerometer angle=-0.929878 current speed= 10.0093 fused angle= -0.09357 voltage= 0.199999

time=4 angle=37.9134 Acelerometer angle=2.71313 current speed= 10.0154 fused angle= 0.030502 voltage= 0.199999

time=4.2 angle=39.9168 Acelerometer angle=0.621527 current speed= 10.0136 fused angle= 1.43891 voltage= 0.199999

time=4.4 angle=41.9201 Acelerometer angle=-0.731017 current speed= 10.0096 fused angle= 0.095482 voltage= 0.199999

time=4.6 angle=43.9233 Acelerometer angle=-3.02105 current speed= 10.0212 fused angle= -1.76944 voltage= 0.199999

time=4.8 angle=45.9263 Acelerometer angle=0.816054 current speed= 10.0107 fused angle= 1.61831 voltage= 0.199999

Final velocity 10.0142

$\bold{Notes}$ 

- What we see is that our accelerometer angle is oscillating due to gravity as our arm rotates.

- Our motor angle is increasing due to the arm spinning continuously.

- Fused angle is oscillating smoothly.