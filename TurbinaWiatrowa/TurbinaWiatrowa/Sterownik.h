#pragma once
#include "Wiatr.h"
#include "StanTurbiny.h"
#include "YawControl.h"
#include "PitchControl.h"
#include "DFIG.h"
#include "PIDMenager.h"
class Sterownik
{

protected:
    Wiatr wiatr;
    StanTurbiny turbina;
    PIDMenager regulatory;
    double predkoscMinimalna;
    double predkoscMaksymalna;
    unsigned int tryb;
public:
    Sterownik();
    void wybierzTryb();
    virtual StanTurbiny obliczNowyStan();
    void wykonajPID();
};