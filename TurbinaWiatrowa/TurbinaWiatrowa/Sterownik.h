#pragma once
#include "Wiatr.h"
#include "StanTurbiny.h"
#include "YawControl.h"
#include "PitchControl.h"
#include "DFIG.h"
class Sterownik
{

protected:
    Wiatr wiatr;
    StanTurbiny turbina;
    double predkoscMinimalna;
    double predkoscMaksymalna;
    unsigned int tryb;
public:
    Sterownik();
    void wybierzTryb();
    virtual StanTurbiny obliczNowyStan();
    void wykonajPID();
};