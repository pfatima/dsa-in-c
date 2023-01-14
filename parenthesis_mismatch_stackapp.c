#include<stdio.h>
#define size 20
#include<string.h>

//lab program 1
//unbalanced parenthesis !without pointers!

int top = -1, i;
char stack1[size], stack[size], ch;

void push(char b);
char pop();

int main(){
    printf("enter the expression: \n");
    scanf("%s", stack1);
    push('#');
    for(i=0; i < strlen(stack1); i++)
    {
        ch = stack1[i];
        if(ch == '(')
            push(ch);
        if(ch ==')')
        {
            if(stack[top]!='#')
                pop();
            else{
                printf("closing parentheses are not balanced\n");
                return 0;
            }
        }

    }
    if(stack[top]=='#')
        printf("parentheses are balanced\n");
    else
        printf("opening parentheses are not balanced\n");
}

void push(char b){
    if(top==size-1)
    {
        return;
    }
    stack[++top] = b;
}

char pop(){
    char val = stack[top];
    top--;
    return(val);
}
