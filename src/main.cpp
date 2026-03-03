//////////////////////////////////////////////
// main.cpp
// initialize and demonstrate firmware loop.
//////////////////////////////////////////////

#include <iostream>
#include "motor/Motor_Model.hpp"
#include "sensors/IMU_Sim.hpp"

int main()
{

// Testing Motor ---------------
Motor::Motor_Model motor;
Sensors::IMU_Sim   imu;

motor.apply_voltage(5.0);


const double DELTA_TIME = 0.001; // 1 ms, 1000 updates per second

for(int i = 0; i < 1000; ++i)
{
    motor.update(DELTA_TIME);
    imu.update(motor.get_velocity());
    std::cout << "time=" << i*DELTA_TIME 
              << " vel= " << motor.get_velocity()
              << " gyro= "<< imu.get_gyro()
              << " accel= " << imu.get_accel() 
              << "\n"; 
}

std::cout << "Final velocity " << motor.get_velocity() << "\n";
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