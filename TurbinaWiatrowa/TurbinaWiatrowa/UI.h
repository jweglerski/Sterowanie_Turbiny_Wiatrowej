#pragma once
class UI{
private:
    double a, b, c;
    double alfa, beta;
public:
    UI(double a, double b, double c);
    UI(double q, double theta, UI x);
    void policzAlfaBeta();
    double q(double theta);
    double d(double theta);
    double Alfa();
    double Beta();
    void odwrotnyPark(double q, double theta, UI x);
    void odwrotnyClarke();
};