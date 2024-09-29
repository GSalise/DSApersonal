#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int *arr;
    int count;
}Stack;

int count(Stack s, int num){
    int val=1;
    
    //technically following a stack since we're starting at the
    // top which is s.count then decrementing by 1 until we reach the end
    if(s.arr)
    while(s.count!=0 && s.arr[s.count-1] < num){
        val++;
        s.count--;
    }
    
    return val;
}

void determineSpan(int *st, int size){
    Stack s;
    s.count = 0;
    s.arr = malloc(sizeof(int) * size);
    
    int deter;
    int *span = malloc(sizeof(int) * size);
    
    for(int i=0; i<size; i++){
        span[i]=count(s, st[i]);
        //still following stack since we're adding from the top
        s.arr[s.count] = st[i];
        s.count++;
    }
    
    
    for(int i = 0; i<size; i++){
        printf("%d ", span[i]);
    }
    
}

int main(){
    int size;
    printf("Enter the number of stocks: ");
    scanf("%d", &size);
    
    int *stocks = malloc(sizeof(int) * size);
    printf("Enter the stock prices:\n");
    
    for(int i=0; i<size; i++){
        scanf("%d", &stocks[i]);
    }
    
    determineSpan(stocks, size);
    
    
    
    return 0;
}
