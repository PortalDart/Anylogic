#include <stdio.h>
#include <math.h>

int main() {
    double vozila = 6859;          // skupno število vozil
    double delezEV = 0.05;         // začetni EV delež (5%)
    
    double emisijaNaKm = 0.00013;  // ton CO2 na km
    double kmLetno = 12653;        // povprečni km/leto

    double rastEV = 0.05;          // 5% prehod na EV letno
    double leta = 30;              // simulacija 30 let

    printf("LETO | EV delez | CO2 emisije (t/leto)\n");
    printf("----------------------------------------\n");

    for (int t = 0; t <= leta; t++) {
        double ICE_vozila = vozila * (1.0 - delezEV);

        double co2 = ICE_vozila * emisijaNaKm * kmLetno;

        printf("%4d |   %.3f  |   %.0f\n", t, delezEV, co2);

        delezEV = delezEV + rastEV * (1.0 - delezEV);

        if (delezEV > 1.0) delezEV = 1.0;
    }

    return 0;
}
