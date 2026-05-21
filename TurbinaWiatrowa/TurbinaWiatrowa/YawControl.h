#pragma once
#include "ModulSterowania.h"
class YawControl:public ModulSterowania{
public:
    YawControl(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr);
    StanTurbiny obliczNowyStan() override;
    bool pozycjaOsiagnieta();
};