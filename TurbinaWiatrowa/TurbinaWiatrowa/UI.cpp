#include "UI.h"
#include <cmath>

UI::UI(double a, double b, double c):a(a),b(b),c(c){
    policzAlfaBeta();
}
void UI::policzAlfaBeta(){
    alfa=(2/3)*(a-b/2-c/2);
    beta=(1/sqrt(3))*(b-c);
}
double UI::q(double theta){
    return -alfa*sin(theta)+beta*cos(theta);
}
double UI::Alfa(){
    return alfa;
}
double UI::Beta(){
    return beta;
}