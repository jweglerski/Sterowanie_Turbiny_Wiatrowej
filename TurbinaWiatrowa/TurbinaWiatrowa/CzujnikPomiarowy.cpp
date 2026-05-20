#include "CzujnikPomiarowy.h"

CzujnikPomiarowy::CzujnikPomiarowy(double kierunekWiatru, double predkoscWiatru, double katPitch, double katYaw, double predkoscObrotowa):kierunekWiatru(kierunekWiatru), predkoscWiatru(predkoscWiatru), katPitch(katPitch), katYaw(katYaw), predkoscObrotowa(predkoscObrotowa){}
Wiatr CzujnikPomiarowy::odczytajWiatr(){
    return Wiatr(kierunekWiatru, predkoscWiatru);
}
StanTurbiny CzujnikPomiarowy::odczytajStan(){
    return StanTurbiny(katPitch, katYaw, predkoscObrotowa);
}