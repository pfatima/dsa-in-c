//stack implementation using array
#include <stdio.h>
#define size 10
int s[size], top = -1, op, op_2;

void push();
void pop();
void display();

void main(){

    do{
        do{
            printf("choose: 1. push, 2. pop, 3. display\n");
            scanf("%d", &op);
            if(op > 3 || op < 1)
                printf("\ninteger should be between 1 and 3\n");
        }while(op > 3 || op < 1);
        switch(op)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
        printf("hit 1 to continue\n");
        scanf("%d", &op_2);
    }while(op_2 == 1);
}

void push(){
    if(top == size-1)
    {
        printf("stack overflow!\n");
        return;
    }
    int ele;
    printf("enter the element to be inserted\n");
    scanf("%d", &ele);
    s[++top] = ele;
}

void pop(){
    if(top == -1)
    {
        printf("stack underflow\n");
        return;
    }
    int val = s[top];
    printf("deleted element is %d\n", val);
    top--;
}

void display(){
    if(top == -1)
    {
        printf("stack underflow\n");
        return;
    }
    printf("stack elements are:\n");
    for(int i = top; i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
}
