#include "Sterownik.h"
#include "StanTurbiny.h"
int main() {
    for (int i = 0; i < 100; i++) {
        double predkoscWiatru = 8;
        double kierunekWiatru = 45;
        Sterownik sterownik(0.6, 0.4, 0.05, 0.6, 0.4, 0.05, 0.6, 0.4, 0.05, 0.6, 0.4, 0.05, 9.98, 5.0, 9231.6);
        auto stanTurbiny = sterownik.czytajWartosci();
        sterownik.obliczNowyStan();
        sterownik.zmierzWiatr(predkoscWiatru, kierunekWiatru);
    }

    return 0;
}