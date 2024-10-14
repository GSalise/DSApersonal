#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node{
    char p;
    struct node *link;
}NodeType, *NodePtr, *Stack; 


bool isEmpty(Stack s){
    return s == NULL;
}

void init(Stack *s){
    *s = NULL;
}

void push(Stack *s, char a){
    NodePtr neww = malloc(sizeof(NodeType));
    neww->p = a;
    neww->link = *s;
    *s = neww;
}

void pop(Stack *s){
    *s = (*s)->link;
}

int prec(char op){
    if(op == '*' || op == '/'){
        return 2;
    }else if(op == '+' || op == '-'){
        return 1;
    }
}

char peek(Stack s){
    return s->p;
}

char *convert(char *infix){
    //PEMDAS
    Stack s;
    init(&s);
    char *postfix = malloc(sizeof(char) * 100);
    int count = 0;
    
    for(int i = 0; i<strlen(infix); i++){
        
        if(infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-'){
            while(!isEmpty(s) && (prec(infix[i]) < prec(peek(s)) || prec(infix[i]) == prec(peek(s)))){
                postfix[count] = peek(s);
                count++;
                pop(&s);
            }
            push(&s, infix[i]);
        }else{
            postfix[count] = infix[i];
            count++;
        }
        
    }
    
    while(!isEmpty(s)){
        postfix[count] = peek(s);
        count++;
        pop(&s);
    }
    
    
    return postfix;
}
//a+b*c+d == abc*+d+
int main(){
    char infix[100];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
  
    printf("Postfix expression: %s", convert(infix));
    
    
    
    
}


