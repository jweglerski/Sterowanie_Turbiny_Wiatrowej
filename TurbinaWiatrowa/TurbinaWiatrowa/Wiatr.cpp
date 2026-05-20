#include "Wiatr.h"

Wiatr::Wiatr(double kierunek, double predkosc):kierunek(kierunek),predkosc(predkosc){};
double Wiatr::podajKierunek(){
    return kierunek;
}
double Wiatr::podajPredkosc(){
    return predkosc;
}