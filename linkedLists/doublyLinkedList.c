//doubly linked list 
#include <stdio.h>
#include <stdlib.h>

//define structure
struct node{
    struct node * prevlink;
    int data;
    struct node * nextlink;
};
//first node AKA head
struct node *head = NULL;
int count; //number of nodes in the doubly linked list

//dll general operations
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void insert_pos();
void delete_pos();
void display();

void print_links(struct node * xyz)
{
    printf("prevlink: %d\nnextlink: %d\ndata: %d\n", xyz->prevlink, xyz->nextlink, xyz->data);
}

void main(){
    int op1, op2;
    do{
        do{
            printf("choose\n1.insert_front\t2.insert_end\t3.delete_front\t4.delete_end\n5.insert@pos\t6.delete@pos\t7.display\n");
            scanf("%d", &op1);
            if(op1 > 7 || op1 < 1)
                printf("enter valid int between 1 & 7 \n");
        }while (op1 > 7 || op1 < 1);
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
            insert_pos();
            display();
            break;
        case 6:
            delete_pos();
            display();
            break;
        case 7:
            display();
            break;
        default:
            printf("invalid!\t;_;");
            break;
        }
        printf("hit 1 to continue\n");
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
    if(head == NULL)
    {
        head = newnode;
        head->nextlink = NULL;
        head->prevlink = NULL;
        return;
    }
    newnode->nextlink = head;
    newnode->prevlink = NULL;
    head->prevlink = newnode;
    head = newnode;
}

void insert_end()
{
    count++;
    struct node * newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("enter data to be inserted <3\n");
    scanf("%d", &newnode->data);
    if(head == NULL)
    {
        head = newnode;
        head->nextlink = NULL;
        head->prevlink = NULL;
        return;
    }
    struct node * temp = head;
    while (temp->nextlink != NULL)
    {
        temp = temp->nextlink;
    }
    temp->nextlink = newnode;
    newnode->prevlink = temp;
    newnode->nextlink = NULL;
}

void delete_front()
{
    if(head == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    /*
        //using temp 
    struct node * temp = head;
    head = head->nextlink;
    head->prevlink = NULL;
    free(temp);
    temp = NULL;
    */
        //without temp
    head = head->nextlink;
    free(head->prevlink);
    head->prevlink = NULL;
    count--;
}

void delete_end()
{
    if(head == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    count--;
    struct node * temp1 = head;
    
    if(temp1->nextlink == NULL)
    {    
        free(temp1);
        temp1 = NULL;
        head = NULL;
        return;
    }
    while(temp1->nextlink != NULL)
    {
        temp1 = temp1->nextlink;
    }
    /*
        //using temp2
    struct node * temp2;
    temp2 = temp1->prevlink;
    free(temp1);
    temp1 = NULL;
    temp2->nextlink = NULL;
    */
        //without temp2
    temp1->prevlink->nextlink = NULL;
    //print_links(temp1);
    free(temp1);
    temp1 = NULL;
}

void insert_pos()
{
    int pos;
    struct node * newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("enter element to be inserted\n");
    scanf("%d", &newnode->data);
    if(head==NULL)
    {
        count++;
        head = newnode;
        head->nextlink = NULL;
        head->prevlink = NULL;
        return;
    }
    do{
        printf("enter position to insert element\n");
        scanf("%d", &pos);
        if(pos < 0 || pos > count + 1)
        printf("enter int between 1 and %d\n", count+1);
    }while(pos > count + 1|| pos < 1);
    printf("node inserted at position %d\n", pos);
    struct node * temp = head; 
    pos-=1;
    if(pos == count)
    {
        insert_end();
        return;
    }
    else if(pos == 0)
    {
        insert_front();
        return;
    }
    while(pos!=0)
    {
        temp = temp->nextlink;
        pos-=1;
    }
    newnode->prevlink = temp->prevlink;
    newnode->nextlink = temp->prevlink->nextlink;
    temp->prevlink->nextlink = newnode;
    temp->prevlink = newnode;
    count++;
    //print_links(temp);
}

void delete_pos()
{
    int pos;
    if(head == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    struct node * temp = head;
    do{
        printf("enter the position to delete element from\n");
        scanf("%d", &pos);
        if(pos > count || pos < 1)
            printf("enter int between 1 and %d >:(\n", count);
    }while(pos > count || pos < 1);
    pos-=1;
    if(pos == count - 1)
    {
        delete_end();
        return;
    }
    else if(pos == 0)
    {
        delete_front();
        return;
    }
    while(pos != 0)
    {
        temp = temp->nextlink;
        pos--; 
    }
    temp->nextlink->prevlink = temp->prevlink;
    temp->prevlink->nextlink = temp->nextlink;
    free(temp);
    temp = NULL;
    count--;
}

void display()
{
    if(head == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    struct node * temp = head;
    if(temp->nextlink!=NULL)
        printf("doubly linked list elements are: ");
    else 
        printf("doubly linked list element: ");
    while(temp->nextlink != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->nextlink;
    }
    printf("%d\n", temp->data); //if temp->nextlink == NULL ie only one node (head node) present  
}
