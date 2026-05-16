#pragma once
#include "Sterownik.h"

class PitchControl:public Sterownik{
private:
    double katMaksymalny;
    double katMinimalny;
public:
    PitchControl();
    void obliczKorekte();
};