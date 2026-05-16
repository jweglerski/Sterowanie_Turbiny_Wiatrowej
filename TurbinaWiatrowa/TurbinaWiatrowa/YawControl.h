#pragma once
#include "Sterownik.h"
class YawControl:public Sterownik{
public:
    void obliczKorekte();
    bool pozycjaOciagnieta();
};