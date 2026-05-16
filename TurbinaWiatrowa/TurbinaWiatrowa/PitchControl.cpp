#include "PitchControl.h"

PitchControl::PitchControl() : katMaksymalny(0), katMinimalny(0) {}
PitchControl::~PitchControl() {}

void PitchControl::obliczKorekce() {}

int  PitchControl::getKatMaksymalny() const { return katMaksymalny; }
int  PitchControl::getKatMinimalny()  const { return katMinimalny; }
void PitchControl::setKatMaksymalny(int kat) { katMaksymalny = kat; }
void PitchControl::setKatMinimalny(int kat)  { katMinimalny  = kat; }
