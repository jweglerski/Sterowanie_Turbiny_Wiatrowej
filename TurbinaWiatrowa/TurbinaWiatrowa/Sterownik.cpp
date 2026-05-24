#include "Sterownik.h"


Sterownik::Sterownik(double kpPitch, double kiPitch, double kdPitch,double kpYaw, double kiYaw, double kdYaw,double kpSpeed, double kiSpeed, double kdSpeed,double kpTorque, double kiTorque, double kdTorque, double K, double predkoscMinimalna, double Kop)
    : wiatr(0,0),
      aktualnyStanTurbiny(0,0,0,0,UI(0,0,0),UI(0,0,0)),
      pozadanyStanTurbiny(0,0,0,0,UI(0,0,0),UI(0,0,0)),
      regulatory(kpPitch, kiPitch, kdPitch, kpYaw, kiYaw, kdYaw, kpSpeed, kiSpeed, kdSpeed, kpTorque, kiTorque, kdTorque),
      czujnik(0,0,0,0,0,0,UI(0,0,0),UI(0,0,0)),
      generator(pozadanyStanTurbiny, regulatory, wiatr, Kop),
      hamowanie(aktualnyStanTurbiny, regulatory, wiatr, 0.1, 10),
      pitchControl(pozadanyStanTurbiny, regulatory, wiatr, K, 50, 0.1, predkoscMinimalna),
      yawControl(aktualnyStanTurbiny, regulatory, wiatr),
      K(K),
      predkoscMinimalna(predkoscMinimalna),
      Kop(Kop)
{
}

StanTurbiny Sterownik::czytajWartosci(){
    wiatr=czujnik.odczytajWiatr();
    aktualnyStanTurbiny=czujnik.odczytajStan();
    pozadanyStanTurbiny=aktualnyStanTurbiny;   
    return aktualnyStanTurbiny;
}
void Sterownik::obliczNowyStan(){
    generator=DFIG(pozadanyStanTurbiny,regulatory,wiatr,Kop);
    pozadanyStanTurbiny=generator.obliczNowyStan();
    pitchControl=PitchControl(pozadanyStanTurbiny,regulatory,wiatr, K, 50, 0.1, predkoscMinimalna);
    pozadanyStanTurbiny=pitchControl.obliczNowyStan();
    yawControl=YawControl(pozadanyStanTurbiny,regulatory,wiatr);
    pozadanyStanTurbiny=yawControl.obliczNowyStan();
    hamowanie=Hamowanie(pozadanyStanTurbiny, regulatory, wiatr, 90, 10); 
    pozadanyStanTurbiny=hamowanie.obliczNowyStan();
    czujnik.zmierzStanTurbiny(regulatory, pozadanyStanTurbiny, aktualnyStanTurbiny);
}
void Sterownik::zmierzWiatr(double predkosc, double kierunek){
    czujnik.zmierzWiatr(predkosc, kierunek);
}
