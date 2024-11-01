#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "amc.c"

int main(){
    Destination a = createDest("Ninoy Aquino International Airport", 1);
    Destination b1 = createDest("Clark International Airport", 2);
    Destination b2 = createDest("Francisco Bangoy International Airport", 2);
    Destination b3 = createDest("Iloilo International Airport", 2);
    Destination c1 = createDest("Panglao International Airport", 3);
    Destination c2 = createDest("Sibulan Airport", 3);
    Destination c3 = createDest("Siquijor Airport", 3);
    Destination d1 = createDest("Bicol International Airport", 4);
    Destination d2 = createDest("Daniel Z. Romualdez Airport", 4);
    Destination d3 = createDest("General Santos International Airport", 4);
    Destination d4 = createDest("Zamboanga International Airport", 4);
    Destination e1 = createDest("Bantayan Airport", 5);
    Destination e2 = createDest("Bulan Airport", 5);
    Destination e3 = createDest("Iba Airport", 5);
    Destination e4 = createDest("Hilongos Airport", 5);
    Destination f1 = createDest("Zamboanga International Airport", 6);
    Destination f2 = createDest("Amoroy Airstrip", 6);

    Schedule sc1 = createSched("0000", "0100");
    Schedule sc2 = createSched("0100", "0900");
    Schedule sc3 = createSched("1000", "1230");
    Schedule sc4 = createSched("2300", "1300");
    Schedule sc5 = createSched("1500", "0600");
    Schedule sc6 = createSched("0000", "0030");
    Schedule sc7 = createSched("0300", "1000");
    Schedule sc8 = createSched("1500", "1900");
    Schedule sc9 = createSched("0600", "0730");
    Schedule sc10 = createSched("0130", "0200");

    Flight flgt1 = createFlight("abc-505", "Boeing", sc1, a);   //prio 1
    Flight flgt2 = createFlight("fac-375", "Airbus", sc5, e1);  //prio 5
    Flight flgt3 = createFlight("mdf-185", "Mazda", sc2, b1);   //prio 2
    Flight flgt4 = createFlight("jyu-385", "Sda", sc3, f1);     //prio 6
    Flight flgt5 = createFlight("asd-058", "Aero", sc9, a);     //prio 1

    AMC amc;
    initAMC(&amc);
    insert(&amc, flgt1);
    insert(&amc, flgt2);
    insert(&amc, flgt3);
    insert(&amc, flgt4);
    insert(&amc, flgt5);

    for(int i = 0; i<amc.count; i++){
        printf("Code: %s\nDestination: %s\nPriority: %d", amc.flight[i]->code, amc.flight[i]->destination.airport, amc.flight[i]->destination.priority);
        printf("\n\n");
    }

    printf("\n\n\n\n\n");

    AMC amc2 = heapsort(&amc);

    for(int i = 0; i<amc2.count; i++){
        printf("Code: %s\nDestination: %s\nPriority: %d", amc2.flight[i]->code, amc2.flight[i]->destination.airport, amc2.flight[i]->destination.priority);
        printf("\n\n");
    }


    return 0;
}