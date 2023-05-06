//reverse a singly linked list 
#include <stdio.h>
#include <stdlib.h>

//define structure
struct node{
    int data;
    struct node * link;
};

typedef struct node * NODE;


NODE insert_front(int data, NODE a);
NODE insert_end(int data, NODE a);
NODE delete_front(NODE a);
NODE delete_end(NODE a);
NODE reverse(NODE a);
void display(NODE a);

NODE reverse(NODE head)
{
    NODE rev = NULL;
    if(head == NULL)
        return head;
    if(head->link == NULL)
        return head;
    NODE curr = head;
    while(curr != NULL)
    {
        rev = insert_front(curr->data, rev);
        curr = curr->link;
    }
    return rev;
}

void main(){
    int n, data;
    NODE head = NULL, rev = NULL;
    printf("enter number of elements: \n");
    scanf("%d", &n);
    printf("enter elements to be inserted in sll\n");
    while(n--)
    {
        scanf("%d", &data);
        head = insert_end(data, head);
    }
    printf("original ");
    display(head);
    rev = reverse(head);
    printf("reversed ");
    display(rev);
}

//insert element at the beginning of the linkedlist
NODE insert_front(int data, NODE head)
{
    struct node * newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode->data = data;
    if(head == NULL)
    {
        head = newnode;
        head->link = NULL;
        return head;
    }
    newnode->link = head;
    head = newnode;
    return head;
}

//insert element at the end of the linkedlist
NODE insert_end(int data, NODE head)
{
    struct node * newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode->data = data;
    if(head == NULL)
    {
        head = newnode;
        newnode->link = NULL;
        return head;
    }
    struct node * temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
    newnode->link = NULL;
    return head;
}

//delete element from beginning of the linkedlist
NODE delete_front(NODE head)
{
    if(head == NULL)
    {
        printf("list is empty :(\n");
        return head;
    }
    struct node * temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
    return head;
}

//delete element at the end of the linkedlist
NODE delete_end(NODE head)
{
    if(head == NULL)
    {
        printf("list is empty :(\n");
        return head;
    }
    struct node * temp1 = head, * temp2;
    if(temp1->link == NULL)
    {    
        free(temp1);
        temp1 = NULL;
        head = NULL;
        return head;
    }
    while(temp1->link != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->link;
    }
    free(temp1);
    temp1 = NULL;
    temp2->link = NULL;
    return head;
}

//display elements in the linkedlist
void display(NODE head)
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
