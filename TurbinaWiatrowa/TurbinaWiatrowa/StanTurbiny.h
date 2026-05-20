#pragma once

class StanTurbiny
{
private:
    double yaw;
    double pitch;
    double obroty;
public:
    StanTurbiny(double pitch, double yaw, double obroty);
    double podajPitch();
    double podajYaw();
    double podajObroty();
};