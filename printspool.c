#include<stdio.h>
#define sz 100
#include<stdlib.h>
int cq[sz], rear=-1, front = 0, count=0;
void insert(int a);
void delete();
void display();

int main()
{
    int item, ch;
    for(;;)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("enter the print job in spool:\n");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a valid number!\n");
        }
    }
    return(0);
}

void insert(int a)
{
    rear = (rear+1)%sz;
    cq[rear] = a;
    count++;
}

void delete()
{
    if(count == 0)
        printf("No job in print spool!\n");
    else
    {
        printf("%d exists in print spool\n", cq[front]);
        front = (front+1)%sz;
        count--;
    }
}

void display()
{

    int i, j;
    if(count==0)
        printf("Print spool is empty!\n");
    else{
        printf("Content of print spool\n");
        j = front;
        for(i=j; i<count; i++)
        {
            printf("%d is printing..\n", cq[j]);
            j = (j+1)%sz;
        }
    }
}
