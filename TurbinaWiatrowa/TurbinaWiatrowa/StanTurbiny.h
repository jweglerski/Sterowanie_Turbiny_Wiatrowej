#pragma once
#include "UI.h"
class StanTurbiny
{
private:
    double yaw;
    double pitch;
    double obroty;
    double T;
    UI u;
    UI i;
public:
    StanTurbiny(double pitch, double yaw, double obroty, double T, UI u, UI i);
    double podajPitch();
    double podajYaw();
    double podajObroty();
    double podajT();
    UI podajU();
    UI podajI();
};