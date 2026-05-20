#pragma once
#include "Sterownik.h"

class PitchControl:public Sterownik{
private:
    double katPitch;
    double K;
    double katMaksymalny;
    double katMinimalny;
public:
    PitchControl();
    StanTurbiny obliczNowyStan() override;
};