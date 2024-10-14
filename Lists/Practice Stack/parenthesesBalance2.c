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

bool hasDuplicate(char *string){
    Stack s;
    s.count = 0;

    for(int i = 0; i<strlen(string); i++){
        if(string[i] == '{' || string[i] == '(' || string[i] == '['){
            push(&s, string[i]);
        }else if(string[i] == '}' || string[i] == ')' || string[i] == ']'){
            while(!isEmpty(s) && peek(s) != '{' && peek(s) != '(' && peek(s) != '['){
                pop(&s);
            }
            if(isEmpty(s)){
                push(&s, string[i]);
                
            }else{
                if((string[i] == '}' && peek(s) == '{') || (string[i] == ')' && peek(s) == '(') || (string[i] == ']' && peek(s) == '['))
                
                
                return true;
            }
        }else{
            push(&s, string[i]);
        }
    }
    
    return false;
}

int main(){
    char string[100];
    printf("Enter a string containing only parentheses: ");
    scanf("%[^\n]s", string);

    
    (hasDuplicate(string) == true) ? printf("Duplicate parentheses found!") : printf("No duplicate parentheses found.");

    
    
    
    
    return 0;
}
