//circular singly linked list 
#include <stdio.h>
#include <stdlib.h>

//define structure
struct node{
    int data;
    struct node * link;
};
struct node *tail = NULL;

void insert_front();
void insert_end();
void delete_front();
void delete_end();
void display();

void main(){
    int op1, op2;
    do{
        do{
            printf("choose\n1.insert_front\t2.insert_end\t3.delete_front\t4.delete_end\t5.display\n");
            scanf("%d", &op1);
            if(op1 > 5 || op1 < 1)
                printf("enter valid int between 1 & 5 >:(\n");
        }while (op1 > 5 || op1 < 1);
        switch (op1)
        {
        case 1:
            insert_front();
            display();
            break;
        case 2:
            insert_end();
            display();
            break;
        case 3:
            delete_front();
            display();
            break;
        case 4:
            delete_end();
            display();
            break;
        case 5:
            display();
            break;
        default:
            printf("invalid!\t;_;");
            break;
        }
        printf("hit 1 to continue\t:)\n");
        scanf("%d", &op2);
    }while(op2 == 1);
}

void insert_front()
{
    struct node * newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("enter data to be inserted <3\n");
        scanf("%d", &newnode->data);
    if(tail == NULL)
    {
        tail = newnode;
        tail->link = tail;
        return;
    }
    newnode->link = tail->link;
    tail->link = newnode;
}

void insert_end()
{
    struct node * newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("enter data to be inserted <3\n");
        scanf("%d", &newnode->data);
    if(tail == NULL)
    {
        newnode->link = newnode;
        tail = newnode;
        return;
    }
    newnode->link = tail->link;
    tail->link = newnode;
    tail = newnode;
}

void delete_front()
{
    if(tail == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    else if(tail->link == tail)
    {
        free(tail);
        tail = NULL;
        return;
    }
    struct node * temp = tail->link;
    tail->link = temp->link;
    free(temp);
    temp = NULL;
}

void delete_end()
{
    if(tail == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    if(tail->link == tail)
    {    
        free(tail);
        tail = NULL;
        return;
    }
    struct node * temp = tail;
    while(temp->link != tail)
    {
        temp = temp->link;
    }
    temp->link = tail->link;
    free(tail);
    tail = temp;
    temp = NULL;
}

void display()
{
    if(tail == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    struct node * temp = tail;
    if(temp->link->link != temp->link) 
    {
        printf("circular singly linked list elements are: \n");
        temp = tail->link;
        do
        {
            printf("%d ", temp->data);
            temp = temp->link;
            if(temp!=tail->link)
            printf(" -> ");
        }while(temp != tail->link);
        printf("\n");
    }
    else
    { 
        printf("circular singly linked list element: ");
        printf("%d\n", tail->link->data);
    }
}
