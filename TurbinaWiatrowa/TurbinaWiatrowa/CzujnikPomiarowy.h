#pragma once
#include "Wiatr.h"
#include "StanTurbiny.h"
#include "PIDMenager.h"
#include "UI.h"
class CzujnikPomiarowy
{
private:
    double kierunekWiatru;
    double predkoscWiatru;
    double katPitch;
    double katYaw;
    double predkoscObrotowa;
    double T;
    UI u;
    UI i;    
public:
    CzujnikPomiarowy(double kierunekWiatru, double predkoscWiatru, double katPitch, double katYaw, double predkoscObrotowa, double T, UI u, UI i);
    Wiatr odczytajWiatr();
    StanTurbiny odczytajStan();
    void zmierzStanTurbiny(PIDMenager regulatory, StanTurbiny pozadanyStanTurbiny, StanTurbiny aktualnyStanTurbiny);
    void zmierzWiatr(double predkosc, double kierunek);
};
