#include "YawControl.h"
YawControl::YawControl(StanTurbiny turbina, PIDMenager regulatory, Wiatr wiatr):ModulSterowania(turbina, regulatory, wiatr){};
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
        return StanTurbiny(turbina.podajPitch(), wiatr.podajKierunek(), turbina.podajObroty(), turbina.podajT(), turbina.podajOmega(), turbina.podajU(), turbina.podajI());
    }
}