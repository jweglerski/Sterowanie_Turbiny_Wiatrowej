#include "CzujnikPomiarowy.h"

CzujnikPomiarowy::CzujnikPomiarowy() : odczytKierunku(0.0), odczytPredkosci(0.0) {}
CzujnikPomiarowy::~CzujnikPomiarowy() {}

void CzujnikPomiarowy::odczytajKierunek() {}
void CzujnikPomiarowy::odczytajPredkosc() {}

double CzujnikPomiarowy::getOdczytKierunku()  const { return odczytKierunku; }
double CzujnikPomiarowy::getOdczytPredkosci() const { return odczytPredkosci; }
