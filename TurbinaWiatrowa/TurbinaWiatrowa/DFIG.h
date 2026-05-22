#pragma once
#include "ModulSterowania.h"
#include "UI.h"
class DFIG:public ModulSterowania{
private:    
    double T;
    double Tref;
    double Kop;
    double omegar;
    UI u;
    UI i;
    UI* un;
    UI* in;
    double theta;
    double iq;
    void obliczT();
    void obliczTheta();
public:
    DFIG(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr, double Kop);
    StanTurbiny obliczNowyStan() override;
};

