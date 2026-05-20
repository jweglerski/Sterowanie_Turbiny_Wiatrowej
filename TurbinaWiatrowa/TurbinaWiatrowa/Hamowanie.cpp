#include "Hamowanie.h"
Hamowanie::Hamowanie(){}
StanTurbiny Hamowanie::obliczNowyStan(){
    wybierzTryb();
    if (tryb==2){
        return StanTurbiny(pitch, turbina.podajYaw(), turbina.podajObroty());
    }
}