#pragma once
#include "Wiatr.h"
#include "StanTurbiny.h"
class CzujnikPomiarowy
{
private:
    double kierunekWiatru;
    double predkoscWiatru;
    double katPitch;
    double katYaw;
    double predkoscObrotowa;
public:
    CzujnikPomiarowy(double kierunekWiatru, double predkoscWiatru, double katPitch, double katYaw, double predkoscObrotowa);
    Wiatr odczytajWiatr();
    StanTurbiny odczytajStan();
};