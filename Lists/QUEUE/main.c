#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"

int main(){
	Queue qA = createQueue();
	
	
	//displayQ(qA);
	for(int i=1; i<6; i++){
		enqueue(&qA, i*2);
		
	}

	displayQ(qA);
	
//	for(int i=0; i<10; i++){
//		dequeue(&qA);
//		diplay(qA);
//	}
	
	
	
	
	return 0.;
}
