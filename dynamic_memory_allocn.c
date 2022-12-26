#include<stdio.h>
#include <stdlib.h>

void main(){
    //calloc
    int *ptr;
    printf("CALLOC\n");
    ptr = (int *) calloc(5,sizeof(int));
    if(ptr==NULL) 
    printf("calloc unsuccessful\n");
    else{
        printf("enter elements:\n");
        for(int i = 0; i < 5; i++)
        scanf("%d", ptr+i);
    }
    printf("the elements: \n");
    for(int i = 0; i < 5; i++)
        printf("%d\t", *(ptr+i));
    free(ptr);
    printf("\n");
    //malloc
    printf("MALLOC\n");
    int *pointer, n, a;
    printf("enter no. of elements:\n");
    scanf("%d", &n);
    pointer = (int *) malloc(n*sizeof(int));
    if(pointer==NULL) 
    printf("malloc unsuccessful\n");
    else{
        printf("enter elements:\n");
        for(int i = 0; i < n; i++)
        scanf("%d", pointer+i);
    }
    printf("the elements: \n");
    for(int i = 0; i < n; i++)
        printf("%d\t", *(pointer+i));
    printf("\n");
    //realloc
    printf("REALLOC\n");
    printf("enter no. of blocks to be added: \n");
    scanf("%d", &a);
    pointer = (int *) realloc(pointer, a*sizeof(int));
    if(pointer==NULL) 
    printf("realloc unsuccessful\n");
    else{
        printf("enter elements:\n");
        for(int i = n ; i < n+a; i++)
        scanf("%d", pointer+i);
    }
    printf("the elements: \n");
    for(int i = 0; i < n+a; i++)
        printf("%d\t", *(pointer+i));
    free(pointer);
}