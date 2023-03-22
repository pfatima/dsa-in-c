//Lab Program 4
//college database 
//using doubly linkedlist

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
    char sname[30], usn[20];
    int sem;
    struct node *llink;
    struct node *rlink;
};

typedef struct node * NODE;
NODE insert(NODE head);
int search(NODE head, char usn[20]);
void display(NODE head);
/*
NODE update(NODE head);
NODE delete(NODE head, int usn);
*/

void main()
{
    int choice, option;
    NODE first = NULL;
    do{
        do{
            printf("choose: 1. Insert\t2. Search\t3. Display\n");
            scanf("%d", &choice);
        }
        while(choice > 3 || choice < 1);
        switch (choice)
        {
        case 1:
            first = insert(first);
            break;
        case 2:
            char usn[20];
            printf("enter usn to be searched\n");
            scanf("%s", usn);
            int a = search(first, usn);
            if(a == 1)
                printf("student found\n");
            else
                printf("student not found\n");
            break;
        case 3:
            display(first);
            break;
        default:
            break;
        }
        printf("hit 1 to continue\n");
        scanf("%d", &option);
    }
    while(option != 2);
}

NODE insert(NODE head)
{
    NODE newnode;
    newnode = (NODE) malloc (sizeof(struct node));
    newnode->llink = newnode->rlink = NULL;
    printf("enter student details :)\n");
    printf("Name: ");
    scanf("%s", newnode->sname);
    printf("USN: ");
    scanf("%s", newnode->usn);
    printf("Semester: ");
    scanf("%d", &newnode->sem);
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    newnode->rlink = head;
    head->llink = newnode;
    head = newnode;
    return head;
}

int search(NODE head, char usn[20])
{
    if(head == NULL)
    {
        printf("college database is empty :(\n");
        return 0;
    }
    NODE temp = head;
    while(temp!= NULL && strcmp(usn, temp->usn) != 0)
    {
        temp = temp->rlink;
    }
    if(temp == NULL)
    return 0;
    else 
    return 1;
}

void display(NODE head)
{
    if(head == NULL)
    {
        printf("college database is empty :(\n");
        return;
    }
    printf("STUDENT DETAILS <3\n");
    printf("|\tName\t|\tUSN\t|\tSemester\n");
    NODE temp = head;
    while(temp!= NULL)
    {
        printf("\t%s\t\t%s\t\t%d\n", temp->sname, temp->usn, temp->sem);
        temp = temp->rlink;
    }
}
