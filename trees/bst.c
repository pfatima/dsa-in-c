// Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

struct node * insert(int data, struct node * root)
{
    struct node *newnode, *curr = NULL, *prev = NULL;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode->data = data;
    newnode->rlink = newnode->llink = NULL;
    
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    curr = root;
    while (curr!=NULL)
    {
        prev = curr;
        if (curr->data == data)
        {
            printf("duplicates are not allowed >:(\n");
            return root;
        }
        if (data < curr->data)
            curr = curr->llink;
        else
            curr = curr->rlink;
    }
    if (data < prev->data)
        prev->llink = newnode;
    else
        prev->rlink = newnode;
    return root;
}

void search (int key, struct node * root)
{
    struct node *temp = root;
    int found = 0;
    while (temp!= NULL)
    {
        if (temp->data == key)
        {
            found = 1;
            printf("key found :)\n");
            return;
        }
        else if (key > temp->data)
            temp = temp->rlink;
        
        else
            temp = temp->llink;
    }
    printf("key not found :(\n");
}

void inorder (struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->llink);
    printf("%d\t", root->data);
    inorder(root->rlink);
}

void preorder (struct node *root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->llink);
    preorder(root->rlink);

}

void postorder (struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t", root->data);

}

void main()
{
    struct node *root = NULL;
    int data, key, insertions = 0, ch, op;
    do{
        do{
            printf("enter choice: 1.Insert\t2.Search\t3.Traversal\n");
            scanf("%d", &ch);
            if (ch < 1 || ch > 3)
                printf("enter value between 1 and 3 >:(\n");
        }while (ch < 1 || ch > 3);
        switch (ch)
        {
        case 1:
            printf("enter no of insertions: \n");
            scanf("%d", &insertions);
            while (insertions--)
            {
                printf("enter data to insert: \n");
                scanf("%d", &data);
                root = insert(data, root);
            }
        break;
            
        case 2:
            if (root == NULL)
            {
                printf("tree not created :(\n");
                return;
            }
            printf("enter key to search: \n");
            scanf("%d", &key);
            search(key, root);
        break;

        case 3:
            if (root == NULL)
            {
                printf("tree not created :(\n");
                return;
            }
            printf("inorder:   ");
            inorder(root);
            printf("\npreorder:  ");
            preorder(root);
            printf("\npostorder: ");
            postorder(root);
        break;

        default:
            break;
        }
        printf("\npress 1 to continue\n");
        scanf("%d", &op);
    }while (op == 1);
}
