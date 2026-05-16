// Sterownik.h
#pragma once

#include "Wiatr.h"
#include "StanTurbiny.h"


class Sterownik
{
protected:
    Wiatr wiatr;
    StanTurbiny stan;
    double predkoscMinimalna;
    unsigned int tryb;
public:
    Sterownik();
    void wybierzTryb();
    StanTurbiny obliczNowyStan();
    void wykonajPID();
};



