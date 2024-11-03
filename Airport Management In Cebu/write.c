#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "amc.h"

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

    Flight flgt1 = createFlight("SHU-005", "Airbus A220", sc1, f2);   
    Flight flgt2 = createFlight("CNG-004", "Airbus A330neo", sc5, e1); 
    Flight flgt3 = createFlight("LIN-003", "Boeing 737", sc2, b1);  
    Flight flgt4 = createFlight("DUS-002", "Boeing 767", sc3, f1);     
    Flight flgt5 = createFlight("NIA-001", "Comac C919", sc10, d4);    
    Flight flgt6 = createFlight("HIS-558", "Sukhoi Superjet SSJ100", sc5, a); 
    Flight flgt7 = createFlight("JYA-158", "Boeing 787 Dreamliner", sc3, b2); 
    Flight flgt8 = createFlight("ASD-758", "Antonov An-148", sc9, a);  
    

    AMC amc;
    initAMC(&amc);
    insert(&amc, flgt1);
    insert(&amc, flgt2);
    insert(&amc, flgt3);
    insert(&amc, flgt4);
    insert(&amc, flgt5);
    insert(&amc, flgt6);
    insert(&amc, flgt7);
    insert(&amc, flgt8);

    AMC amc2 = heapsort(&amc);

    FILE *fp;

    char code[8];
    printf("Welcome to AMC Flight Lists!\nTo view a list of flights that are in line ahead of yours, please enter your flight code.\nFlight Code: ");
    scanf("%s", code);
    printf("\n\n");

    fp = fopen("flight_list.dat", "wb");

    if(fp != NULL){
        for(int i = 0; i<amc2.count  && strcmp(amc2.flight[i]->code, code) != 0; i++){
            fwrite(amc2.flight[i], sizeof(NodeType), 1, fp);
        }
    }

    fclose(fp);

    return 0;
}