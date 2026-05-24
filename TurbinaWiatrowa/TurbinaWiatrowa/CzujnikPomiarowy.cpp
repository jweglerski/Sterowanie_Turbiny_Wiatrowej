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
    double zmianaPitch = regulatory.updatePitch(pozadanyStanTurbiny.podajPitch(), aktualnyStanTurbiny.podajPitch());
    if (zmianaPitch > 1.0){
        zmianaPitch = 1.0;
    }
    if (zmianaPitch < -1.0){
        zmianaPitch = -1.0;
    }
    katPitch = aktualnyStanTurbiny.podajPitch() + zmianaPitch;

    // Wieza nie przeskakuje od razu, tylko powoli dochodzi do kierunku wiatru.
    double bladYaw = pozadanyStanTurbiny.podajYaw() - aktualnyStanTurbiny.podajYaw();
    while (bladYaw > 180){
        bladYaw -= 360;
    }
    while (bladYaw < -180){
        bladYaw += 360;
    }
    double zmianaYaw = regulatory.updateYaw(aktualnyStanTurbiny.podajYaw() + bladYaw, aktualnyStanTurbiny.podajYaw());
    if (zmianaYaw > 3.0){
        zmianaYaw = 3.0;
    }
    if (zmianaYaw < -3.0){
        zmianaYaw = -3.0;
    }
    katYaw = aktualnyStanTurbiny.podajYaw() + zmianaYaw;
    while (katYaw >= 360){
        katYaw -= 360;
    }
    while (katYaw < 0){
        katYaw += 360;
    }

    if (katPitch < 0.1){
        katPitch = 0.1;
    }
    if (katPitch > 50){
        katPitch = 50;
    }

    if (predkoscWiatru < 3.0){
        predkoscObrotowa = 0;
    }else if (predkoscWiatru > 10.0){
        predkoscObrotowa = aktualnyStanTurbiny.podajObroty() * 0.95;
    }else{
        // Prosta charakterystyka pracy wirnika:
        // turbina rusza od ok. 3 m/s, do 10 m/s przyspiesza,
        // a powyzej tego zakresu wlacza sie hamowanie.
        double obrotyZadane;
        obrotyZadane = (predkoscWiatru - 3.0) * 8.0;
        if (obrotyZadane < 0){
            obrotyZadane = 0;
        }

        double wspolczynnikPitch = cos(katPitch * 3.14159265358979323846 / 180.0);
        if (wspolczynnikPitch < 0){
            wspolczynnikPitch = 0;
        }
        predkoscObrotowa = obrotyZadane * wspolczynnikPitch;
    }
    if (predkoscObrotowa < 0){
        predkoscObrotowa = 0;
    }
    T=pozadanyStanTurbiny.podajT();
    u=pozadanyStanTurbiny.podajU();
    i=pozadanyStanTurbiny.podajI();
}
void CzujnikPomiarowy::zmierzWiatr(double predkosc, double kierunek){
    predkoscWiatru=predkosc;
    kierunekWiatru=kierunek;
}
