#include "YawControl.h"

YawControl::YawControl() : aktualnyKat(0.0), docelowyKat(0.0) {}
YawControl::~YawControl() {}

void YawControl::obliczKorekce() {}
bool YawControl::pozycjaOsagnieta() { return false; }

double YawControl::getAktualnyKat() const { return aktualnyKat; }
double YawControl::getDocelowyKat() const { return docelowyKat; }
void   YawControl::setDocelowyKat(double kat) { docelowyKat = kat; }
