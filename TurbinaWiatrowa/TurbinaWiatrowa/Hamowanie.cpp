#include "Hamowanie.h"
Hamowanie::Hamowanie(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr, double pitch, double predkoscMaksymalna):ModulSterowania(turbina, regulatory, wiatr), pitch(pitch), predkoscMaksymalna(predkoscMaksymalna){};
StanTurbiny Hamowanie::obliczNowyStan(){
    if (wiatr.podajPredkosc()>predkoscMaksymalna){
        return StanTurbiny(pitch, turbina.podajYaw(), turbina.podajObroty(), turbina.podajT(), turbina.podajOmega(), turbina.podajU(), turbina.podajI());
    }
}