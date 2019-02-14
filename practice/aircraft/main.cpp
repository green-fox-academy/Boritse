#include <iostream>
#include "F16.h"
#include "F35.h"
#include "carrier.h"

int main() {

    F16 Dani;
    F35 Boro;
    F35 Gyuri;
    F35 Snocc;
    F16 Adam;

    Carrier carrier(500, 4000);
    carrier.add(&Dani);
    carrier.add(&Boro);
    carrier.add(&Gyuri);
    carrier.add(&Snocc);
    carrier.add(&Adam);
    carrier.fill();

    F16 Arpi;
    F16 KisP;
    F16 Zoltan;
    F35 Veikko;
    F16 Benji;

    Carrier otherCarrier(382, 3210);
    otherCarrier.add(&Arpi);
    otherCarrier.add(&KisP);
    otherCarrier.add(&Zoltan);
    otherCarrier.add(&Veikko);
    otherCarrier.add(&Benji);

    carrier.fight(otherCarrier);
    std::cout << otherCarrier.getHP();

    carrier.fill();
    carrier.fight(otherCarrier);

    return 0;
}