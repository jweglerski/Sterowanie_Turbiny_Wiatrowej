#include "PID.h"
PID::PID(double kp, double ki, double kd):kp(kp),ki(ki),kd(kd){
    e=0;
    i=0;
    lastE=0;
    firstUpdate=true;
}
double PID::dt(){
    if (firstUpdate){
        firstUpdate=false;
        now=std::chrono::steady_clock::now();
        lastTime=now;
        return 0;
    }else{
        now=std::chrono::steady_clock::now();
        double dt=std::chrono::duration_cast<std::chrono::milliseconds>(now-lastTime).count()/1000.0;
        lastTime=now;
        return dt;
    }
}
void PID::error(double target, double pomiar){
    lastE=e;
    e=target-pomiar;
}
void PID::integer(){
    i+=e*dt();
}
double PID::update(double target, double pomiar){
    error(target, pomiar);
    integer();
    return kp*e+ki*i+kd*(e-lastE)/dt();
}
void PID::reset(){
    e=0;
    i=0;
    lastE=0;
    firstUpdate=true;
}
