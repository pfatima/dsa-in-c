//circular queue
#include<stdio.h>
#define max 10
int i, rear = -1, front = -1, op, option, insertions, deletions, q[max], size;
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
        }while(option > 3);

    switch(option)
    {
        case 1:
        {
            insert();
        }
        break;
        case 2:
        {
            //if(rear == 0)
            delete();
            /*else{
                //printf("enter number of deletions: \n");
                scanf("%d", &deletions);
                for(int i = 0; i < deletions; i++)
                    delete();
             */   //display();
            //}
        }
        break;
        case 3:
            display();
        break;
    }
    printf("hit 1 to continue:\n");
    scanf("%d", &op);
    }while(op == 1);
}

void create(){
    do{
        printf("enter size of queue: \n");
        scanf("%d", &size);
    }while(size >= max);
    printf("queue created of size %d\n", size);
}

void insert(){

    int data;
    if((front == rear + 1) || (front == 0 && rear == size - 1))
    {
        printf("queue is full\n");
        return;
    }
    if(front == -1)
        front++;
    /*do{
        printf("enter number of insertions: \n");
        scanf("%d", &insertions);
        if((insertions + (rear+1)%size)> size-1 )
            printf("too many insertions\n");
    }while((insertions+(rear+1)%size)>size-1);
    while(insertions--)
    {*/
        rear = (rear + 1) % size;
        printf("enter integer element: \n");
        scanf("%d", &data);
        q[rear] = data;
    //}
}

void delete(){
    int ele;
    if(front == -1)
    {
        printf("queue is empty\n");
        return;
    }
    ele = q[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    }
    else
        front = (front + 1) % size;

    printf("deleted element: %d \n", ele);
    

}

void display(){
    if(rear == -1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("elements are:\n");
    {
        for(i = front; i != rear; i= (i+1)%size)
            printf("%d\t", q[i]);
        printf("%d\n", q[i]);
    }
}

/*
void shift(){
    for(int i = 0; i< rear; i++)
    q[i] = q[i+1];
}
*/
