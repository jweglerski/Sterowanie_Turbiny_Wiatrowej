#pragma once
class UI{
private:
    double a, b, c;
    double alfa, beta;
public:
    UI(double a, double b, double c);
    void policzAlfaBeta();
    double q(double theta);
    double Alfa();
    double Beta();
};