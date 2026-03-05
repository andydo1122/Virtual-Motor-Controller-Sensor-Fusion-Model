//////////////////////////////////////////////
// main.cpp
// initialize and demonstrate firmware loop.
//////////////////////////////////////////////

#include <iostream>
#include "motor/Motor_Model.hpp"
#include "sensors/IMU_Sim.hpp"
#include "control/PID.hpp"

int main()
{

// Testing ---------------
Motor::Motor_Model motor;
Sensors::IMU_Sim   imu;
// Clamp voltage from -12 to 12
Control::PID       controller(0.5, 0.1, 0.01, -12.0, 12.0); // example gains;

const double DELTA_TIME = 0.001;  // 1 ms, 1000 updates per second
const double TARGET_SPEED = 100.0; // rad/s

for(int i = 0; i < 5000; ++i)
{
    motor.update(DELTA_TIME);
    imu.update(motor.get_velocity());

    double current_speed = imu.get_gyro(); // gyro is equivalent to angular velocity
    double error = TARGET_SPEED - current_speed; 

    double voltage_cmd = controller.update(error, DELTA_TIME); 

    motor.apply_voltage(voltage_cmd);

    if(i % 100 == 0)
    {
        std::cout << "time=" << i*DELTA_TIME 
                  << " current_speed= "<< current_speed
                  << " voltage= " << voltage_cmd
                  << "\n"; 
    }
}

std::cout << "Final velocity " << motor.get_velocity() << "\n";
// Testing ---------------

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