// Sterownik.h
#pragma once

#include "Wiatr.h"
#include "StanTurbiny.h"
#include "PID.h"
#include "YawControl.h"
#include "PitchControl.h"
#include "Hamowanie.h"

public ref class Sterownik
{
public:
    Wiatr^ wiatr;
    StanTurbiny^ stan;

    PID^ pid;
    YawControl^ yaw;
    PitchControl^ pitch;
    Hamowanie^ hamowanie;

    Sterownik()
    {

    }
};