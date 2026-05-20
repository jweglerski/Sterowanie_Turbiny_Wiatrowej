#include "PitchControl.h"
PitchControl::PitchControl(){};
StanTurbiny PitchControl::obliczNowyStan(){
    wybierzTryb();
    if(tryb==1){
        katPitch=wiatr.podajPredkosc()*K;
        return StanTurbiny(katPitch, turbina.podajYaw(), turbina.podajObroty());
    }
}