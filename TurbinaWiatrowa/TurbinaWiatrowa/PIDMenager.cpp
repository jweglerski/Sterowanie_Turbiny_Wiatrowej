#include "PIDMenager.h"

PIDMenager::PIDMenager(double kpPitch, double kiPitch, double kdPitch,
                         double kpYaw, double kiYaw, double kdYaw,
                         double kpSpeed, double kiSpeed, double kdSpeed,
                         double kpTorque, double kiTorque, double kdTorque):
                         pitchPID(kpPitch,kiPitch,kdPitch),
                         yawPID(kpYaw,kiYaw,kdYaw),
                         speedPID(kpSpeed,kiSpeed,kdSpeed),
                         torquePID(kpTorque,kiTorque,kdTorque)
{}
PIDMenager::~PIDMenager(){}
double PIDMenager::updatePitch(double target, double pomiar){
    return pitchPID.update(target,pomiar);
}
double PIDMenager::updateYaw(double target, double pomiar){
    return yawPID.update(target,pomiar);
}
double PIDMenager::updateSpeed(double target, double pomiar){
    return speedPID.update(target,pomiar);
}
double PIDMenager::updateTorque(double target, double pomiar){
    return torquePID.update(target,pomiar);
}
