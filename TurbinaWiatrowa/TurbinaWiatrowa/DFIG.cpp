#include "DFIG.h"
#include <cmath>
DFIG::DFIG(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr, double Kop)
    : ModulSterowania(turbina, regulatory, wiatr), omegar(turbina.podajObroty()), Kop(Kop), Tref(turbina.podajT()), u(turbina.podajU()), i(turbina.podajI()){
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
    double predkoscWiatru = wiatr.podajPredkosc();
    double obrotyZadane = 0;
    if (predkoscWiatru >= 3 && predkoscWiatru <= 10){
        obrotyZadane = (predkoscWiatru - 3.0) * 8.0;
    }
    Tref = Kop * obrotyZadane * obrotyZadane;
    iq=regulatory.updateSpeed(Tref,T);
    UI un(regulatory.updateTorque(i.q(theta), iq), theta, u);
    UI in(iq, theta, i);
    return StanTurbiny(turbina.podajPitch(), turbina.podajYaw(), turbina.podajObroty(), T, un, in);
}
