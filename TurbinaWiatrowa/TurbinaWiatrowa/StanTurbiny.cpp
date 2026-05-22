#include "StanTurbiny.h"

StanTurbiny::StanTurbiny(double pitch, double yaw, double obroty, double T, UI u, UI i):pitch(pitch),yaw(yaw),obroty(obroty),T(T),u(u),i(i){};
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

UI StanTurbiny::podajU(){
    return u;
}
UI StanTurbiny::podajI(){
    return i;
}