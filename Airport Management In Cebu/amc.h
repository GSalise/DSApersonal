#ifndef AMC_H
#define AMC_H
#define MAX 10

typedef struct{
    int departure;
    int arrival;
}Schedule;

typedef struct{
    char airport[100];
    int priority;
}Destination;

typedef struct{
    char code[8];
    char aircraft[100];
    Schedule flightSched;
    Destination destination;
}NodeType, *NodePtr, *Flight;

typedef struct{
    Flight flight[10];
    int count;
}AMC;

Schedule createSched(char *departure, char *arrival);
Destination createDest(char *airport, int priority);
Flight createFlight(char *code, char *aircraft, Schedule flightSched, Destination destination);
int compareSched(Schedule a, Schedule b);
void initAMC(AMC *a);
void insert(AMC *a, Flight f);
AMC heapsort(AMC *a);
void heapify(AMC *a, int n);
void printList(NodeType a);

#endif