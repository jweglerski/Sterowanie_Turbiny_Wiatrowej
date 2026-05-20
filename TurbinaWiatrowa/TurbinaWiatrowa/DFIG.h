#pragma once
#include "Sterownik.h"
#include "UI.h"
class DFIG:public Sterownik{
private:    
    double T;
    double Kop;
    double omegar;
    UI u;
    double theta;
public:
    DFIG(double omegar, double Kop, UI u);
    void obliczT();
    void obliczTheta();
    StanTurbiny obliczNowyStan() override;
};

