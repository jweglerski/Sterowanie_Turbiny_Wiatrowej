#include "CzujnikPomiarowy.h"
#include "cmath"
#include "StanTurbiny.h"
CzujnikPomiarowy::CzujnikPomiarowy(double kierunekWiatru, double predkoscWiatru, double katPitch, double katYaw, double predkoscObrotowa, double T, UI u, UI i):kierunekWiatru(kierunekWiatru), predkoscWiatru(predkoscWiatru), katPitch(katPitch), katYaw(katYaw), predkoscObrotowa(predkoscObrotowa), T(T), u(u), i(i){}
Wiatr CzujnikPomiarowy::odczytajWiatr(){
    return Wiatr(kierunekWiatru, predkoscWiatru);
}
StanTurbiny CzujnikPomiarowy::odczytajStan(){
    return StanTurbiny(katPitch, katYaw, predkoscObrotowa, T, u, i);
}
void CzujnikPomiarowy::zmierzStanTurbiny(PIDMenager regulatory, StanTurbiny pozadanyStanTurbiny, StanTurbiny aktualnyStanTurbiny){
    katPitch=regulatory.updatePitch(pozadanyStanTurbiny.podajPitch(), aktualnyStanTurbiny.podajPitch());
    katYaw=regulatory.updateYaw(pozadanyStanTurbiny.podajYaw(), aktualnyStanTurbiny.podajYaw());
    predkoscObrotowa=predkoscWiatru/(40*tan(katPitch));
    T=pozadanyStanTurbiny.podajT();
    u=pozadanyStanTurbiny.podajU();
    i=pozadanyStanTurbiny.podajI();
}
void CzujnikPomiarowy::zmierzWiatr(double predkosc, double kierunek){
    predkoscWiatru=predkosc;
    kierunekWiatru=kierunek;
}