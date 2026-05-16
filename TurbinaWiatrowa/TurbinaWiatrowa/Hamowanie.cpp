#include "Hamowanie.h"

Hamowanie::Hamowanie() : pitch(0), hamuje(false) {}
Hamowanie::~Hamowanie() {}

void Hamowanie::ustawPitch() {}

int  Hamowanie::getPitch()  const { return pitch; }
void Hamowanie::setPitch(int nowyPitch) { pitch = nowyPitch; }
bool Hamowanie::czyHamuje() const { return hamuje; }
