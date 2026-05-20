#pragma once
#include "Sterownik.h"
class YawControl:public Sterownik{
public:
    StanTurbiny obliczNowyStan() override;
    bool pozycjaOsiagnieta();
};