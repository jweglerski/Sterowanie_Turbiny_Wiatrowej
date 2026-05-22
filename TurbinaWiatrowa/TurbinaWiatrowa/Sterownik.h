#pragma once
#include "Wiatr.h"
#include "StanTurbiny.h"
#include "YawControl.h"
#include "PitchControl.h"
#include "DFIG.h"
#include "PIDMenager.h"
#include "CzujnikPomiarowy.h"
#include "Hamowanie.h"

class Sterownik
{
private:
    Wiatr wiatr;
    StanTurbiny aktualnyStanTurbiny;
    StanTurbiny pozadanyStanTurbiny;
    PIDMenager regulatory;
    CzujnikPomiarowy czujnik;
    DFIG generator;
    Hamowanie hamowanie;
    PitchControl pitchControl;
    YawControl yawControl;
    double Kop;
    double K;
    double predkoscMinimalna;

public:
    Sterownik(double kpPitch, double kiPitch, double kdPitch,
              double kpYaw, double kiYaw, double kdYaw,
              double kpSpeed, double kiSpeed, double kdSpeed,
              double kpTorque, double kiTorque, double kdTorque, double K, double predkoscMinimalna, double Kop);
    StanTurbiny czytajWartosci();
    void obliczNowyStan();
    void zmierzWiatr(double predkosc, double kierunek);
};
