#include "Sterownik.h"

Sterownik::Sterownik(){}
void Sterownik::wybierzTryb(){
    if(wiatr.podajPredkosc()<predkoscMinimalna){
        tryb=0;
    }else if(wiatr.podajPredkosc()>predkoscMaksymalna){
        tryb=2;
    }else{
        tryb=1;
    }
}
StanTurbiny Sterownik::obliczNowyStan(){
}
void Sterownik::wykonajPID(){

}
