#pragma once
#include "StanTurbiny.h"
#include "PIDMenager.h"  
#include "Wiatr.h"
class ModulSterowania{
protected:
    StanTurbiny turbina;
    PIDMenager regulatory;
    Wiatr wiatr;
public:
    ModulSterowania(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr);
    virtual StanTurbiny obliczNowyStan()=0;    
};