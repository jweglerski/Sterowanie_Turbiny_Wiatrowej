#include "UI.h"
#include <cmath>

UI::UI(double a, double b, double c):a(a),b(b),c(c){
    policzAlfaBeta();
}
UI::UI(double q, double theta, UI x){
    odwrotnyPark(q, theta, x);
    odwrotnyClarke();
}
void UI::policzAlfaBeta(){
    alfa=(2/3)*(a-b/2-c/2);
    beta=(1/sqrt(3))*(b-c);
}
double UI::q(double theta){
    return -alfa*sin(theta)+beta*cos(theta);
}
double UI::d(double theta){
    return alfa*cos(theta)+beta*sin(theta);
}
double UI::Alfa(){
    return alfa;
}
double UI::Beta(){
    return beta;
}
void UI::odwrotnyPark(double q, double theta, UI x){
    alfa=-q*sin(theta)+x.d(theta)*cos(theta);
    beta=q*cos(theta)+x.d(theta)*sin(theta);
}
void UI::odwrotnyClarke(){
    a=alfa;
    b=-alfa/2+beta*sqrt(3)/2;
    c=-alfa/2-beta*sqrt(3)/2;
}