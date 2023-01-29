//stack implementation using array with parameter passing to fn
#include <stdio.h>

void push(int *top, int stackSize, int stack[]);
void pop(int *top, int stackSize, int stack[]);
void display(int *top, int stackSize, int stack[]);

void main(){
    int size, top = -1, op, op_2;

    printf("enter size of stack: \n");
    scanf("%d", &size);
    int s[size];
    
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
            push(&top, size, s);
            break;
        case 2:
            pop(&top, size, s);
            break;
        case 3:
            display(&top, size, s);
            break;
        }
        printf("hit 1 to continue\n");
        scanf("%d", &op_2);
    }while(op_2 == 1);
}

void push(int *top, int stackSize, int stack[]){
    if(*top == stackSize-1)
    {
        printf("stack overflow! cannot insert more elements\n");
        return;
    }
    int ele;
    printf("enter the element to be inserted\n");
    scanf("%d", &ele);
    *top += 1;
    stack[*top] = ele;
}

void pop(int *top, int stackSize, int stack[]){
    if(*top == -1)
    {
        printf("stack underflow! cannot delete any more elements\n");
        return;
    }
    int val = stack[*top];
    printf("deleted element is %d\n", val);
    *top -= 1;
}

void display(int *top, int stackSize, int stack[]){
    if(*top == -1)
    {
        printf("stack underflow\n");
        return;
    }
    printf("stack elements are:\n");
    for(int i = *top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
