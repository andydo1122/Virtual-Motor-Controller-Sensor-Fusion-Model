//////////////////////////////////////////////
// main.cpp
// initialize and demonstrate firmware loop.
//////////////////////////////////////////////

// int main()
// {
//     Scheduler scheduler(1); 

//     MotorModel motor;
//     IMUSim imu;
//     PID pid(1.0, 0.1, 0.01);

//     scheduler.addTask(1, [&]()
//     {
//         imu.update(motor.getAngularVelocity());
//     });

//     scheduler.addTask(5, [&]()
//     {
//         double angle   = imu.getAngle();
//         double control = pid.update(targetAngle - angle);
//         motor.applyVoltage(control);

//     });

//     scheduler.addTask(10, [&]()
//     {
//         CANFrame frame = makeMotorStatusFrame(motor);
//         MessageBus::Publish(frame);
//     });

//     scheduler.run();
// }