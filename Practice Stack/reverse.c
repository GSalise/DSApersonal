#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct{
    char arr[100];
    int count;
}Stack;

bool isEmpty(Stack s){
    return s.count == 0;
}

void push(Stack *s, char p){
    s->count++;
    s->arr[s->count] = p;
}

void pop(Stack *s){
    s->count--;
}

char peek(Stack s){
    return s.arr[s.count];
}

Stack reverse(char *string){
    Stack s;
    s.count = 0;
    
    for(int i=0; i<strlen(string); i++){
        push(&s, string[i]);
    }
    
   return s;
    
    
}

int main(){
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);
    
    Stack rev = reverse(string);
    
    printf("Reversed string:\n");
    while(!isEmpty(rev)){
    	printf("%c", peek(rev));
    	pop(&rev);
	}
    
    
    
    
    return 0;
}
