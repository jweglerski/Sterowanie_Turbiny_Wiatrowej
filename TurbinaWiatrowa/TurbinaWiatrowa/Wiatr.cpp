#include "Wiatr.h"

Wiatr::Wiatr() : Kierunek(0.0), Predkosc(0.0) {}
Wiatr::~Wiatr() {}

void Wiatr::zmianaKierunku(double nowyKierunek) { Kierunek = nowyKierunek; }
void Wiatr::zmianaPredkosci(double nowaPredkosc) { Predkosc = nowaPredkosc; }
void Wiatr::symulujPodmuch(double predkosc) { Predkosc = predkosc; }

double Wiatr::getKierunek()  const { return Kierunek; }
double Wiatr::getPredkosc()  const { return Predkosc; }
void Wiatr::setKierunek(double kierunek) { Kierunek = kierunek; }
void Wiatr::setPredkosc(double predkosc) { Predkosc = predkosc; }
