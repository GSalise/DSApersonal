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

    while(n > 0 && a->flight[(n - 1) / 2]->destination.priority <= f->destination.priority){
        
        //if the prio is the same then compare flight schedules
        //if the child has a higher value the loop continues otherwise quit
        if(a->flight[(n - 1) / 2]->destination.priority == f->destination.priority){
            if(compareSched(a->flight[(n - 1) / 2]->flightSched, f->flightSched) == -1){
                break;
            }
        }else{
            a->flight[n] = a->flight[(n - 1) / 2];
            n = (n - 1) / 2;
        }
    }

    a->flight[n] = f;
    a->count++;
}


AMC heapsort(AMC *a){
    AMC neww = *a;

    for(int i = neww.count - 1; i>=0; i--){
        Flight temp = malloc(sizeof(NodeType));
        temp = neww.flight[0];

        neww.flight[0] = neww.flight[i];
        neww.flight[i] = temp;
        neww.count--;
        heapify(&neww, 0);
    }

    neww.count = a->count;

    return neww;
}

void heapify(AMC *a, int n){
    int left = (2 * n) + 1;
    int right = (2 * n) + 2;
    int lowest = n;

    if(left < a->count && a->flight[left]->destination.priority >= a->flight[lowest]->destination.priority){

        int leftprio = a->flight[left]->destination.priority;
        int lowprio = a->flight[lowest]->destination.priority;

        if(leftprio > lowprio || (leftprio == lowprio && compareSched(a->flight[left]->flightSched, a->flight[lowest]->flightSched) == 1 )){
            lowest = left;
        }
    }

    if(right < a->count && a->flight[right]->destination.priority >= a->flight[lowest]->destination.priority){

        int rightprio = a->flight[right]->destination.priority;
        int lowprio = a->flight[lowest]->destination.priority;

        if(rightprio > lowprio || (rightprio == lowprio && compareSched(a->flight[right]->flightSched, a->flight[lowest]->flightSched) == 1 )){
            lowest = right;
        }
    }

    if(lowest != n){
        Flight temp = malloc(sizeof(NodeType));

        temp = a->flight[lowest];
        a->flight[lowest] = a->flight[n];
        a->flight[n] = temp;
        heapify(a, lowest);
    }
}

void printList(NodeType a){
    printf("Code: %s\nAirport: %s\nAircraft: %s\nPriority: %d\n\n", a.code, a.destination.airport, a.aircraft, a.destination.priority);
}

