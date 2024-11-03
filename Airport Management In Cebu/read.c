#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "amc.h"

int main(){
    FILE *fp;
    NodeType a;

    fp = fopen("flight_list.dat", "rb");

    if(fp!=NULL){
        while(fread(&a, sizeof(NodeType), 1, fp)){
            printList(a);
        }
    }

    fclose(fp);

    return 0;
}