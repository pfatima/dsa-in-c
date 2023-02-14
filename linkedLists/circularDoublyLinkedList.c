//circular doubly linked list 
#include <stdio.h>
#include <stdlib.h>

//define structure
struct node{
    struct node * prevlink;
    int data;
    struct node * nextlink;
};

struct node *tail = NULL;
int count; //number of nodes in the doubly linked list

//circular dll general operations
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void display();

void print_links(struct node * xyz)
{
    printf("prevlink: %d\nnextlink: %d\ndata: %d\n", xyz->prevlink, xyz->nextlink, xyz->data);
}

void main(){
    int op1, op2;
    do{
        do{
            printf("choose\n1.insert_front\t2.insert_end\t3.delete_front\t4.delete_end\t5.display\n");
            scanf("%d", &op1);
            if(op1 > 5 || op1 < 1)
                printf("enter valid int between 1 & 5 \n");
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
        printf("hit 1 to continue <3\n");
        scanf("%d", &op2);
    }while(op2 == 1);
}

void insert_front()
{
    count++;
    struct node * newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("enter data to be inserted <3\n");
        scanf("%d", &newnode->data);
    if(tail == NULL)
    {
        tail = newnode;
        tail->data = newnode->data;
        tail->nextlink = tail;
        tail->prevlink = tail;
        return;
    }
    newnode->nextlink = tail->nextlink;
    newnode->prevlink = tail;
    tail->nextlink->prevlink = newnode;
    tail->nextlink = newnode;
}

void insert_end()
{
    count++;
    struct node * newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("enter data to be inserted <3\n");
    scanf("%d", &newnode->data);
    if(tail == NULL)
    {
        tail = newnode;
        tail->nextlink = tail;
        tail->prevlink = tail;
        return;
    }
    newnode->prevlink = tail;
    newnode->nextlink = tail->nextlink;
    tail->nextlink->prevlink = newnode;
    tail->nextlink = newnode;
    tail = newnode;
}

void delete_front()
{
    if(tail == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    if(tail->nextlink == tail)
    {
        free(tail);
        tail == NULL;
        return;
    }
    struct node *temp = tail->nextlink;
    tail->nextlink = temp->nextlink; 
    temp->nextlink->prevlink = temp->prevlink;
    free(temp);
    temp = NULL;
    count--;
}

void delete_end()
{
    if(tail == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    count--;
    if(tail->nextlink == tail)
    {
        free(tail);
        tail == NULL;
        return;
    }
    struct node *temp = tail->prevlink;
    temp->nextlink = tail->nextlink;
    temp->nextlink->prevlink = temp;
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
    struct node *temp = tail->nextlink;
    if(tail->nextlink != tail)
    {
        printf("circular doubly linkedlist elements are: \n");
        do{
            printf("%d ", temp->data);
            temp = temp->nextlink;
            if(temp != tail->nextlink)
            printf(" -> ");
        }while(temp != tail->nextlink);
    }
    else
    {
        printf("circular doubly linkedlist element: ");
        printf("%d", temp->data);
    }
    printf("\n");
}
