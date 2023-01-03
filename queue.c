#include<stdio.h>
#define max 10
int i, rear = -1, front = 0, op, option, insertions, deletions, q[max], size;
void create();
void insert();
void delete();
void display();
//void shift();
void main(){
    create();
    do{
        do{
            printf("choose among the foll: 1.insert, 2.delete, 3.display\n");
            scanf("%d", &option);
        }while(option>3);


    switch(option)
    {
        case 1:
        {
            insert();
        }
        break;
        case 2:
        {
            if(rear == 0)
            delete();
            else{
                printf("enter number of deletions: \n");
                scanf("%d", &deletions);
                for(int i = 0; i < deletions; i++)
                    delete();
                //display();
            }
        }
        break;
        case 3:
            display();
        break;
    }
    printf("hit 1 to continue:\n");
    scanf("%d", &op);
    }while(op==1);
}

void create(){
    do{
        printf("enter size of queue: \n");
        scanf("%d", &size);
    }while(size>=max);
    printf("queue created of size %d\n", size);
    printf("rear: %d \nsize: %d \nfront: %d\n", rear, size ,front);
}

void insert(){
    int data;
    if(rear == size -1)
    {
        printf("queue is full\n");
        return;
    }
    do{
        printf("enter number of insertions: \n");
        scanf("%d", &insertions);
        if((insertions + rear)> size-1 )
            printf("too many insertions\n");
    }while((insertions+rear)>size-1);
    while(insertions--)
    {
        printf("enter integer element: \n");
        scanf("%d", &data);
        q[++rear] = data;
    }
    //printf("rear: %d \nsize: %d \nfront: %d\n",rear, size, front);
}

void delete(){
    int ele;
    if(rear==-1)
    {
        printf("queue is empty\n");
        return;
    }
    ele = q[front];

    front++;
    //size++;

    printf("deleted element: %d \n", ele);
    //printf("rear: %d \nsize: %d \nfront: %d\n",rear, size, front);

    //shift();
    //rear--;

}

void display(){
    if(rear == -1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("elements are:\n");
    for(i = front; i <= rear; i++)
        printf("%d\t", q[i]);
    printf("\n");
    //printf("rear: %d \nsize: %d \nfront: %d\n", rear, size, front);
}

/*
void shift(){
    for(int i = 0; i< rear; i++)
    q[i] = q[i+1];
}
*/
