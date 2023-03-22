//lab program 2
//print spooler application using queue (circular)

#include <stdio.h>
#define sz 100
#include <stdlib.h>

int cq[sz], rear =- 1, front = 0, count = 0;

void insert(int a);
void delete();
void display();
//void print_rfc(); 

void print_rfc()
{
    printf("rear: %d\tfront: %d\tcount: %d\n", rear, front, count);
}

int main()
{
    int item, ch;
    for(;;)
    {
        printf("Enter your choice:\n1.Insert\t2.Delete\n3.Show status\t4.Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("enter the printer job in the print spooler:\n");
                scanf("%d", &item);
                insert(item);
                //display();
                break;
            case 2:
                delete();
                //display();
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
    rear = (rear + 1) % sz;
    cq[rear] = a;
    count++;
}

void delete()
{
    if(count == 0)
        printf("No job in print spooler!\n");
    else
    {
        printf("%d exits the print spooler\n", cq[front]);
        front = (front + 1) % sz;
        count--;
    }
}

void display()
{
    //print_rfc();
    int i, j;
    if(count == 0)
        printf("Print spooler is empty!\n");
    else{
        printf("Content of print spooler:\n");
        if(rear==front && count == 1)
        {
            printf("%d is printing..\n", cq[rear]);
            return;
        }
        j = front;
        
        for(i = j; i < count; i++)
        {
            printf("%d is printing..\n", cq[j]);
            j = (j + 1) % sz;
        }
    }
}
