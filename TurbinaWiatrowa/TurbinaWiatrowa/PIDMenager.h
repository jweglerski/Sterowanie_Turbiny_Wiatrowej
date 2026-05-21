#pragma once
#include "PID.h"
class PIDMenager{
private:
    PID* pitchPID; 
    PID* yawPID;
    PID* speedPID;
    PID* torquePID;
public:
    PIDMenager(double kpPitch, double kiPitch, double kdPitch,
                double kpYaw, double kiYaw, double kdYaw,
                double kpSpeed, double kiSpeed, double kdSpeed,
                double kpTorque, double kiTorque, double kdTorque);
    ~PIDMenager();
    double updatePitch(double target, double pomiar);
    double updateYaw(double target, double pomiar);
    double updateSpeed(double target, double pomiar);
    double updateTorque(double target, double pomiar);
};