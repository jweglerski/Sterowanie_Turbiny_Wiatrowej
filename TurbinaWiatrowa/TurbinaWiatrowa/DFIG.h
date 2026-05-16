#pragma once
#include "Sterownik.h"

class DFIG:public Sterownik{
public:
    void obliczKorekte();
    void obliczTete();
};
class U:public DFIG{
public:
    void obliczU();
};
class I:public DFIG{
public:
    void obliczI();
};
