#include "YawControl.h"
YawControl::YawControl(){};
bool YawControl::pozycjaOsiagnieta(){
    if (turbina.podajYaw()==wiatr.podajKierunek()){
        return true;
    }else{
        return false;
    }
}
StanTurbiny YawControl::obliczNowyStan(){
    if(YawControl::pozycjaOsiagnieta()){
        return turbina;
    }else{
        return StanTurbiny(turbina.podajPitch(), wiatr.podajKierunek(), turbina.podajObroty());
    }
}