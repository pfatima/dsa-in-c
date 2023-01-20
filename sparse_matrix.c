//2D array representation of sparse matrix 
#include <stdio.h>
#define MAX 20
int i, j, r, c, tot;
struct sparse_matrix{
    int row;
    int col;
    int val;
};
struct sparse_matrix s[MAX], s_t[MAX];

void create();
void transpose();

void main(){
    create();
    transpose();
}

void create(){
    int value, k = 0;
    tot = 0; //count of non-zero values
    printf("enter number of rows and columns: \n");
    scanf("%d %d", &s[0].row, &s[0].col);
    r = s[0].row;
    c = s[0].col;
    printf("enter the elements: \n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &value);
            if(value != 0)
            {
                s[k].row = i;
                s[k].col = j;
                s[k].val = value;
                tot++;
                k++;
            }
            //printf("%d", val[i][j]);
        }
    }
    printf("ROW\tCOLUMN\tVALUE\n");
    printf("%d\t%d\t%d\n", r, c, tot);
    for(k = 0; k < tot; k++)
    printf("%d\t%d\t%d\n", s[k].row+ 1, s[k].col+ 1, s[k].val);
}
void transpose(){
    int k = 0;
    printf("transpose: \n");
    /*for(i= 0; i <c; i++)
    {
        for(j= 0; j <r; j++)
            printf("%d\t", s[j].val);
        printf("\n");
    }
    for(j= 0; j < tot; j++)
            printf("%d\t", s[j].val);
    printf("\n");
    */
    for(i=0; i < tot; i++)
    {
        for(j = 0; j < tot; j++)
        {
            if(s[j].col == i)
            {
                s_t[k].row = s[j].col;
                s_t[k].col = s[j].row;
                s_t[k].val = s[j].val;
                k++;
            }
        }
    }
    printf("ROW\tCOLUMN\tVALUE\n");
    printf("%d\t%d\t%d\n", c, r, tot);
    for(k = 0; k < tot; k++)
    printf("%d\t%d\t%d\n", s_t[k].row+ 1, s_t[k].col+ 1, s_t[k].val);
}
