#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node{
    char par;
    struct node *link;
}NodeType, *NodePtr, *Stack;

bool isBalanced(char *string);
bool isEmpty(Stack s);
bool push(Stack *s, char p);
bool pop(Stack *s);
char peek(Stack s);

int main(){
    char string[100];
    
    printf("Enter a string with parentheses: ");
    scanf("%s", string);
    
    (isBalanced(string) == true) ? printf("The parentheses are balanced!") : printf("The parentheses are not balanced!");

    
    return 0;
}

bool isBalanced(char *string){
    Stack s = NULL;
    
    for(int i = 0; i<strlen(string); i++){
        if(string[i] == '{' || string[i] == '(' || string[i] == '['){
            push(&s, string[i]);
        }
        if(string[i] == '}' || string[i] == ')' || string[i] == ']'){
            if(isEmpty(s)){
                return false;
            }
            if(string[i] == '}' && peek(s) == '{'){
                pop(&s);
            }
            if(string[i] == ')' && peek(s) == '('){
                pop(&s);
            }
            if(string[i] == ']' && peek(s) == '['){
                pop(&s);
            }
        }
    }
    
    return (isEmpty(s)) ? true : false;
    
}

bool isEmpty(Stack s){
    return s == NULL;
}

bool push(Stack *s, char p){
    NodePtr neww = malloc(sizeof(NodeType));
    
    neww->par = p;
    neww->link = *s;
    *s = neww;
}


bool pop(Stack *s){
    *s = (*s)->link;
}
char peek(Stack s){
    return s->par;
}
