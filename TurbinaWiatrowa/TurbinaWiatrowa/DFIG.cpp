#include "DFIG.h"
#include <cmath>
DFIG::DFIG(double omegar, double Kop, UI u): omegar(omegar), Kop(Kop), u(u){
    obliczT();
    obliczTheta;
}
void DFIG::obliczT(){
    T=Kop*omegar*omegar;
}
void DFIG::obliczTheta(){
    theta=atan2(u.Beta(),u.Alfa());
}

StanTurbiny DFIG::obliczNowyStan(){
    
}