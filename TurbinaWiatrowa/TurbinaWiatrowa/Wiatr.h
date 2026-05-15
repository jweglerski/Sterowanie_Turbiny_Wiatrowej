#pragma once

public ref class Wiatr
{
public:
    double predkosc;
    double kierunek;

    Wiatr()
    {

    }

    void ustawWarunki(double nowaPredkosc, double nowyKierunek)
    {
        predkosc = nowaPredkosc;
        kierunek = nowyKierunek;
    }
};