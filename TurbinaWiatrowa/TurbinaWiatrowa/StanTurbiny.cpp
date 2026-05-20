#include "StanTurbiny.h"

StanTurbiny::StanTurbiny(double pitch, double yaw, double obroty):pitch(pitch),yaw(yaw),obroty(obroty){};
double StanTurbiny::podajPitch(){
    return pitch;
}
double StanTurbiny::podajYaw(){
    return yaw;
}
double StanTurbiny::podajObroty(){
    return obroty;
}