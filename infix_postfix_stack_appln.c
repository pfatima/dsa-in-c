#include <stdio.h>
#include <ctype.h>
#define size 10

char postfix[20], infix[20], stack[20];
char symbol;
int top = -1;

int pre(char a);
void push(char b);
char pop();
void infix_postfix();
void postfix_eval();

void main()
{
    printf("enter infix expression:\n");
    scanf("%s", infix);
    printf("%s\n", infix);
    infix_postfix();
    printf("postfix: %s\n", postfix);
    postfix_eval();
}

void infix_postfix(){
    int i = 0, k = 0;
    stack[++top] = '#';
    //printf("stack[0] = %c\n", stack[top]);
    while((symbol = infix[i++])!='\0')
    {
    //printf("symbol = %c\n", symbol);
        if(isalnum(symbol))
            postfix[k++] = symbol;

        else if(symbol == '(')
            push(symbol);

        else if (symbol == ')')
        {
            while(stack[top]!='(')
                postfix[k++] = pop();
            char ele = pop();
        }

        else
        {
            while(pre(stack[top]) >= pre(symbol))
                postfix[k++] = pop();
            push(symbol);
        }
    }
    
    while (stack[top]!='#')
    {
        postfix[k++] = pop();
    } 
}

void postfix_eval()
{
    int i = 0, op1, op2, res;
    char symbol;
    
    while ((symbol = postfix[i++]) != '\0')
    {
        if (isdigit(symbol))
            push(symbol - '0');
        else
        {
            op2 = pop();
            op1 = pop();
            switch (symbol)
            {
                case '+':
                    res = op1 + op2;
                    break;

                case '-':
                    res = op1 - op2;
                    break;

                case '*':
                    res = op1 * op2;                
                    break;

                case '/':
                    res = op1 / op2;
                    break;

                case '%':
                    res = op1 % op2;
                    break;
                }
                push(res);
        }
    }
    printf("result is %d\n", pop());
}

void push(char b){
    if(top == size - 1)
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

int pre(char a){
    if(a == '*' || a == '/' || a == '%')
        return 2;
    else if(a == '+' || a == '-')
        return 1;
    else
        return 0;
}
