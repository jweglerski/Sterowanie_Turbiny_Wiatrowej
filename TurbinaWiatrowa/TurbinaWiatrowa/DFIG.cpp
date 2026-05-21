#include "DFIG.h"
#include <cmath>
DFIG::DFIG(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr, double omegar, double Kop, double Tref, UI u, UI i)
    : ModulSterowania(turbina, regulatory, wiatr), omegar(omegar), Kop(Kop), Tref(Tref), u(u), i(i){
    obliczT();
    obliczTheta();
}
void DFIG::obliczT(){
    T=Kop*omegar*omegar;
}
void DFIG::obliczTheta(){
    theta=atan2(u.Beta(),u.Alfa());
}

StanTurbiny DFIG::obliczNowyStan(){
    obliczT();
    obliczTheta();
    iq=regulatory.updateSpeed(Tref,T);
    un=new UI(regulatory.updateTorque(i.q(theta), iq), theta, u);
    in=new UI(iq, theta, i);
    return StanTurbiny(turbina.podajPitch(), turbina.podajYaw(), turbina.podajObroty(), T, turbina.podajOmega(), un, in);
}
