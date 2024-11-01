#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "amc.h"

int main(){
    FILE *fp;
    NodeType a;
    char code[8];
    printf("Welcome to AMC Flight Lists!\nTo view a list of flights that are in line ahead of yours, please enter your flight code.\nFlight Code: ");
    scanf("%s", code);
    printf("\n\n");

    fp = fopen("flight_list.dat", "rb");

    if(fp!=NULL){
        while(fread(&a, sizeof(NodeType), 1, fp) && strcmp(a.code , code) != 0){
            printList(a);
        }
    }

    fclose(fp);

    return 0;
}