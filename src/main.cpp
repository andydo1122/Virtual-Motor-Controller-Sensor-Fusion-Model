//////////////////////////////////////////////
// main.cpp
// initialize and demonstrate firmware loop.
//////////////////////////////////////////////

#include <iostream>
#include "motor/Motor_Model.hpp"

int main()
{

// Testing Motor ---------------
Motor::Motor_Model motor;
motor.apply_voltage(5.0);

for(int i = 0; i < 1000; ++i)
{
    motor.update(0.001);
}

std::cout << "Final velocity " << motor.get_velocity() << std::endl; 
// Testing Motor ---------------

// WHEN EVERYTHING IS IMPLEMENTED...
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

    return 0;
}