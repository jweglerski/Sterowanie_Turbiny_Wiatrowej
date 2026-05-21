#include "PitchControl.h"
PitchControl::PitchControl(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr, double K, double katMaksymalny, double katMinimalny, double predkoscMinimalna):ModulSterowania(turbina, regulatory, wiatr), K(K), katMaksymalny(katMaksymalny), katMinimalny(katMinimalny), predkoscMinimalna(predkoscMinimalna){};
StanTurbiny PitchControl::obliczNowyStan(){
    if(wiatr.podajPredkosc()>predkoscMinimalna){
        katPitch=wiatr.podajPredkosc()*K;
        return StanTurbiny(katPitch, turbina.podajYaw(), turbina.podajObroty(), turbina.podajT(), turbina.podajOmega(), turbina.podajU(), turbina.podajI());
    }
}