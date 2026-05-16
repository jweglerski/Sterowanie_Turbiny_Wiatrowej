#pragma once
#include "Sterownik.h"

class Hamowanie:public Sterownik{
public:
    double pitch;
private:
    void ustawPitch();
};