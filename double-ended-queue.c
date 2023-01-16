#include<stdio.h>

#define max 10

int i, rear = -1, front = -1, op, option, insertions, deletions, q[max], size, count=0;

void create();
void insert_rear();
void insert_front();
void delete_rear();
void delete_front();
void display();
void print_rfs();

//void shift();

void main(){
    create();
    do{
        do{
            printf("choose among the foll: 1. insert_rear, 2. delete_front, 3. display 4. insert_front, 5. delete_rear\n");
            scanf("%d", &option);
        }while(option>5);


    switch(option)
    {
        case 1:
        {
            insert_rear();
        }
        break;
        case 2:
        {
            display();
            if(count>0)
            {
                do{
                    printf("enter number of deletions: \n");
                    scanf("%d", &deletions);
                    if(deletions>count)
                    printf("enter integer less than %d(number of elements present)\n", count);
                }while(deletions>count || deletions < 0);
                if(deletions<=count)
                {
                    while(deletions--)
                        delete_front();
                    //display();
                }
            }
        }
        break;
        case 3:
            display();
        break;
        case 4:
            insert_front();
        break;
        case 5:
        {
            display();
            if(count>0)
            {
                do{
                printf("enter number of deletions: \n");
                scanf("%d", &deletions);
                if(deletions>count)
                    printf("enter integer less than or equal to %d(number of elements present)\n", count);
                }while(deletions>count || deletions < 0);
                if(deletions<=count)
                {
                    while(deletions--)
                        delete_rear();
                }
            }
        }
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
        if(size>=max)
        printf("enter size < %d\n", max);
    }while(size>=max);
    printf("queue created of size %d\n", size);
    //print_rfs();
    display();
}

void insert_rear(){
    int data;
    //print_rfs();
    if(rear == size -1 && front == 0 || front > rear)
    {
        printf("queue is full at rear\n");
        return;
    }
    //print_rfs();
    if(front==-1)
    {
        front++;
    }
    //print_rfs();
    do{
        printf("enter number of insertions: \n");
        scanf("%d", &insertions);
        if((insertions + rear)> size-1 )
            printf("too many insertions\n");
    }while((insertions+rear)>size-1);
    //print_rfs();
    while(insertions--)
    {
        printf("enter integer element: \n");
        scanf("%d", &data);
        q[++rear] = data;
    }
    //print_rfs();
    display();
}

void insert_front(){
    //print_rfs();
    int data;
    if(front == 0)
    {
        printf("queue is full at front\n");
        return;
    }
    do{
        printf("enter number of insertions: \n");
        scanf("%d", &insertions);
        if((insertions + rear)> size-1 )
            printf("too many insertions\n");
    }while(insertions+rear>size-1);
    while(insertions--)
    {
        if(front==-1 && rear == -1)
        {
            front++;
            rear++;
        }
        else if(front == 0)
        {
            rear++;
            for(i=rear; i>=0; i--)
            q[i+1]=q[i];
        }
        else
        {
            front--;
        }
        //print_rfs();
        printf("enter integer element:\n");
        scanf("%d", &data);
        //print_rfs();
        q[front] = data;
        //printf("location:%d\telement:%d\n", front, data);
        //print_rfs();
        display();
    }
}

void delete_rear(){
    int ele;
    //print_rfs();
    if(rear==-1 || rear < front)
    {
        printf("queue is empty at rear!\n");
        return;
    }
    ele = q[rear];
    rear--;
    printf("deleted element is: %d\n", ele);
    display();
}

void delete_front(){
    //print_rfs();
    int ele;
    if(rear==-1 && front == -1)
    {
        printf("queue is empty\n");
        return;
    }
    if(front==-1)
    front++;
    ele = q[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(front<0)
        front = 0;
    else front++;
    
    //front++;
    //size++;??
    
    printf("deleted element: %d \n", ele);
    //print_rfs();
    // insted of incrementing front, 
    //shift all elements to the left + decrement rear??

    //shift();    
    //rear--;
    display();
}

void display(){
    count = 0;
    //print_rfs();
    if(rear == -1 && front == -1 || rear < front )
    {
        printf("queue is empty\n");
        return;
    }
    if(front == 0 && rear == 0 || (front == rear) && front!= -1)
    {
        printf("element is: ");
        printf("%d\n", q[rear]);
        count = 1;
        return;
    }
    printf("locations\telements\n");
    for(i = front; i <= rear; i++)
    {
        printf("%d\t\t%d\n", i, q[i]);
        count++;
    }
    //printf("%d\t", q[i]);
    //printf("\n");
    //printf("number of elements = %d\n", count);
    //print_rfs();
}

void print_rfs(){
    printf("rear: %d\tsize: %d\tfront: %d\n",rear, size, front);
}
/*
void shift(){
    for(int i = 0; i< rear; i++)
    q[i] = q[i+1];
}
*/
