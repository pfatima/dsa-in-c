//singly linked list 
#include <stdio.h>
#include <stdlib.h>

//define structure
struct node{
    int data;
    struct node * link;
};
struct node * head = NULL;

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
                printf("enter valid int between 1 & 5\n");
        } while (op1 > 5 || op1 < 1);
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
            printf("invalid!\t");
            break;
        }
        printf("hit 1 to continue\n");
        scanf("%d", &op2);
    } while(op2 == 1);
}

//insert element at the beginning of the linkedlist
void insert_front()
{
    struct node * newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("enter data to be inserted <3\n");
        scanf("%d", &newnode->data);
    if(head == NULL)
    {
        head = newnode;
        head->link = NULL;
        return;
    }
    newnode->link = head;
    head = newnode;
}

//insert element at the end of the linkedlist
void insert_end()
{
    struct node * newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    printf("enter data to be inserted <3\n");
        scanf("%d", &newnode->data);
    if(head == NULL)
    {
        head = newnode;
        newnode->link = NULL;
        return;
    }
    struct node * temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
    newnode->link = NULL;
}

//delete element from beginning of the linkedlist
void delete_front()
{
    if(head == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    struct node * temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
}

//delete element at the end of the linkedlist
void delete_end()
{
    if(head == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    struct node * temp1 = head, * temp2;
    if(temp1->link == NULL)
    {    
        free(temp1);
        temp1 = NULL;
        head = NULL;
        return;
    }
    while(temp1->link != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->link;
    }
    free(temp1);
    temp1 = NULL;
    temp2->link = NULL;
}

//display elements in the linkedlist
void display()
{
    if(head == NULL)
    {
        printf("list is empty :(\n");
        return;
    }
    struct node * temp = head;
    if(temp->link != NULL)
        printf("singly linked list elements are: \n");
    else 
        printf("singly linked list element: ");
    while(temp->link != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("%d\n", temp->data);
}
