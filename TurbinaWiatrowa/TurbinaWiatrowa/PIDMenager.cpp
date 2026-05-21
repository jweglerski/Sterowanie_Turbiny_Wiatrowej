#include "PIDMenager.h"

PIDMenager::PIDMenager(double kpPitch, double kiPitch, double kdPitch,
                         double kpYaw, double kiYaw, double kdYaw,
                         double kpSpeed, double kiSpeed, double kdSpeed,
                         double kpTorque, double kiTorque, double kdTorque):
                         pitchPID(new PID(kpPitch,kiPitch,kdPitch)),
                         yawPID(new PID(kpYaw,kiYaw,kdYaw)),
                         speedPID(new PID(kpSpeed,kiSpeed,kdSpeed)),
                         torquePID(new PID(kpTorque,kiTorque,kdTorque))
{}
PIDMenager::~PIDMenager() {
    delete pitchPID;
    delete yawPID;
    delete speedPID;
    delete torquePID;
}
double PIDMenager::updatePitch(double target, double pomiar){
    return pitchPID->update(target,pomiar);
}
double PIDMenager::updateYaw(double target, double pomiar){
    return yawPID->update(target,pomiar);
}
double PIDMenager::updateSpeed(double target, double pomiar){
    return speedPID->update(target,pomiar);
}
double PIDMenager::updateTorque(double target, double pomiar){
    return torquePID->update(target,pomiar);
}