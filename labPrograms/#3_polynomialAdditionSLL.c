//Lab Program 3
//polynomial addition
//using singly linkedlist
#include<stdio.h>
#include<stdlib.h>

struct node {
    int expo;
    int coeff;
    struct node *link;
};

typedef struct node NODE;

struct node * insert(struct node * head, int exponent, int coefficient)
{
    struct node *temp, *newP;
    newP = (struct node *)malloc(sizeof(NODE));
    newP->coeff = coefficient;
    newP->expo = exponent;
    newP->link = NULL; 
    if(head == NULL || exponent > head->expo)
    {
        newP->link = head;
        head = newP;
    }
    else
    {
        temp = head;
        while(temp->link != NULL && temp->link->expo >= exponent)
            temp = temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

struct node * create(struct node * pol)
{
    int terms, coeff, expo;
    printf("Enter the Polynomial Expression: \n");
    do
    {
        printf("Enter the number of terms\n");
        scanf("%d", &terms);
    }
    while (terms < 0);
    int i = 1;
    while(terms != 0)
    {
        printf("Enter coefficient and the exponent for term number %d: \n", i);
        scanf("%d %d", &coeff, &expo);
        pol = insert(pol, expo, coeff);
        i++; terms--;
    }
    return pol;
}

void printPol(struct node *head)
{
    if(head == NULL)
    {
        printf("no polynomial :(\n");
    }
    else{
        struct node *temp = head;
        while(temp!=NULL)
        {
            printf("%dx^%d", temp->coeff, temp->expo);
            if(temp->link != NULL) 
            {
                printf(" + ");
            }
            else printf("\n");
            temp = temp->link;    
        }       
        
    }
}

void polyAdd(struct node *h1, struct node *h2)
{
    struct node *p1 = h1;
    struct node *p2 = h2;
    struct node *h3 = NULL;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->expo == p2->expo)
        {
            h3 = insert(h3, p1->expo, p1->coeff + p2->coeff);
            p1 = p1->link;
            p2 = p2->link;
        }
        else if(p1->expo > p2->expo)
        {
            h3 = insert(h3, p1->expo, p1->coeff);
            p1 = p1->link;
        }
        else if(p2->expo > p1->expo)
        {
            h3 = insert(h3, p2->expo, p2->coeff);
            p2 = p2->link;
        }
    }
    while(p1 != NULL)
    {
        h3 = insert(h3, p1->expo, p1->coeff);
        p1 = p1->link;
    }
    while(p2 != NULL)
    {
        h3 = insert(h3, p2->expo, p2->coeff);
        p2 = p2->link;
    }
    printf("sum of the two polynomials is: \n");
    printPol(h3);
}

void main()
{
    struct node * pol1, *pol2;
    pol1 = pol2 = NULL;
    pol1 = create(pol1);
    pol2 = create(pol2);
    printf("\nthe first polynomial expression is : \n");
    printPol(pol1);
    printf("\nthe second polynomial expression is : \n");
    printPol(pol2);
    polyAdd(pol1, pol2);
}
