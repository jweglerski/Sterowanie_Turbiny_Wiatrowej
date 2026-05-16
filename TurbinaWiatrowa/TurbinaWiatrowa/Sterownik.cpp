#include "Sterownik.h"

Sterownik::Sterownik()
    : predkoscMinialna(0.0),
      trybPracy(0),
      itsStanTurbiny(new StanTurbiny()),
      itsWiatr(new Wiatr()),
      itsPID(new PID()),
      itsYawControl(new YawControl()),
      itsPitchControl(new PitchControl()),
      itsDFIG(new DFIG()),
      itsHamowanie(new Hamowanie()),
      itsInterfejs(new Interfejs()),
      itsU(new U()),
      itsI(new I()),
      itsCzujnik(new CzujnikPomiarowy())
{}

Sterownik::~Sterownik() {
    delete itsStanTurbiny;
    delete itsWiatr;
    delete itsPID;
    delete itsYawControl;
    delete itsPitchControl;
    delete itsDFIG;
    delete itsHamowanie;
    delete itsInterfejs;
    delete itsU;
    delete itsI;
    delete itsCzujnik;
}

void Sterownik::obliczNowyStan(StanTurbiny& stanTurbiny) {}
void Sterownik::wybierzTryb() {}
void Sterownik::wykonaPID() {}

void Sterownik::symulujPodmuchWiatru(double predkosc) { itsWiatr->symulujPodmuch(predkosc); }
void Sterownik::symulujZmianaKierunku(double kierunek) { itsWiatr->setKierunek(kierunek); itsYawControl->setDocelowyKat(kierunek); }
void Sterownik::symulujAwarie() { trybPracy = -1; itsHamowanie->setPitch(90); }
void Sterownik::symulujHamowanie() { itsHamowanie->setPitch(90); itsHamowanie->ustawPitch(); }
void Sterownik::resetuj() { trybPracy = 0; itsWiatr->setPredkosc(0.0); itsWiatr->setKierunek(0.0); itsYawControl->setDocelowyKat(0.0); itsHamowanie->setPitch(0); }

double Sterownik::getPredkoscWiatru()  const { return itsWiatr->getPredkosc(); }
double Sterownik::getKierunekWiatru()  const { return itsWiatr->getKierunek(); }
double Sterownik::getKatYaw()          const { return itsYawControl->getAktualnyKat(); }
double Sterownik::getKatPitch()        const { return static_cast<double>(itsPitchControl->getKatMaksymalny()); }
bool   Sterownik::czyHamuje()          const { return itsHamowanie->czyHamuje(); }
int    Sterownik::getTrybPracy()       const { return trybPracy; }
void   Sterownik::setTrybPracy(int tryb) { trybPracy = tryb; }
