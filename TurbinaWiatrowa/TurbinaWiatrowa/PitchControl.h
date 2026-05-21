#pragma once
#include "ModulSterowania.h"

class PitchControl:public ModulSterowania{
private:
    double predkoscMinimalna;
    double katPitch;
    double K;
    double katMaksymalny;
    double katMinimalny;
public:
    PitchControl(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr, double K, double katMaksymalny, double katMinimalny, double predkoscMinimalna);
    StanTurbiny obliczNowyStan() override;
};