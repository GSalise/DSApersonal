#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "amc.h"

Schedule createSched(char *departure, char *arrival){
    Schedule neww;
    neww.arrival = atoi(arrival);
    neww.departure = atoi(departure);
    return neww;
}

Destination createDest(char *airport, int priority){
    Destination neww;
    strcpy(neww.airport, airport);
    neww.priority = priority;
    return neww;
}

Flight createFlight(char *code, char *aircraft, Schedule flightSched, Destination destination){
    Flight neww = malloc(sizeof(NodeType));
    strcpy(neww->code, code);
    strcpy(neww->aircraft, aircraft);
    neww->flightSched = flightSched;
    neww->destination = destination;
    return neww;
}

// If the parent has a higher value then return 1 otherwise -1
int compareSched(Schedule a, Schedule b){
    int f1 = a.arrival + a.departure;
    int f2 = b.arrival + b.departure;

    return (f1 > f2) ? 1 : -1;
}

void initAMC(AMC *a){
    for(int i = 0; i<MAX; i++){
        a->flight[i] = NULL;
    }
    a->count = 0;
}

void insert(AMC *a, Flight f){
    int n = a->count;
    int parent = (n - 1) / 2;

    while(n > 0 && a->flight[parent]->destination.priority >= f->destination.priority){
        
        //if the prio is the same then compare flight schedules
        //if the child has a higher value the loop continues otherwise quit
        if(a->flight[parent]->destination.priority == f->destination.priority){
            if(compareSched(a->flight[parent]->flightSched, f->flightSched) == -1){
                break;
            }
        }else{
            a->flight[n] = a->flight[parent];
            n = parent;
        }
    }

    a->flight[n] = f;
    a->count++;
}

