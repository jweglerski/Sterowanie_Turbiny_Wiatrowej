#include "PitchControl.h"
PitchControl::PitchControl(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr, double K, double katMaksymalny, double katMinimalny, double predkoscMinimalna):ModulSterowania(turbina, regulatory, wiatr), K(K), katMaksymalny(katMaksymalny), katMinimalny(katMinimalny), predkoscMinimalna(predkoscMinimalna){};
StanTurbiny PitchControl::obliczNowyStan(){
    double predkoscHamowania = 10.0;

    if(wiatr.podajPredkosc() <= predkoscMinimalna){
        katPitch = katMinimalny;
    }else if(wiatr.podajPredkosc() >= predkoscHamowania){
        katPitch = katMaksymalny;
    }else{
        // Od malego kata roboczego turbina przechodzi liniowo do maksymalnego wychylenia.
        double udzial = (wiatr.podajPredkosc() - predkoscMinimalna) / (predkoscHamowania - predkoscMinimalna);
        katPitch = katMinimalny + udzial * (katMaksymalny - katMinimalny);
    }

    if (katPitch < katMinimalny){
        katPitch = katMinimalny;
    }
    if (katPitch > katMaksymalny){
        katPitch = katMaksymalny;
    }

    return StanTurbiny(katPitch, turbina.podajYaw(), turbina.podajObroty(), turbina.podajT(), turbina.podajU(), turbina.podajI());
}
