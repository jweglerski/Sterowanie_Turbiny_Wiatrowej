#pragma once
#include "ModulSterowania.h"

class Hamowanie:public ModulSterowania{
private:
    double pitch;
    double predkoscMaksymalna;
public:
    Hamowanie(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr, double pitch, double predkoscMaksymalna);
    StanTurbiny obliczNowyStan() override;
};