#include "StanTurbiny.h"

StanTurbiny::StanTurbiny(double pitch, double yaw, double obroty, double T, double omega, UI* u, UI* i):pitch(pitch),yaw(yaw),obroty(obroty),T(T),omega(omega),u(u),i(i){};
double StanTurbiny::podajPitch(){
    return pitch;
}
double StanTurbiny::podajYaw(){
    return yaw;
}
double StanTurbiny::podajObroty(){
    return obroty;
}
double StanTurbiny::podajT(){
    return T;
}
double StanTurbiny::podajOmega(){
    return omega;
}
UI* StanTurbiny::podajU(){
    return u;
}
UI* StanTurbiny::podajI(){
    return i;
}