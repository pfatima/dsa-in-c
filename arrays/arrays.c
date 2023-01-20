#include <stdio.h>
#define max 10
int a[max], insertions, deletions, n, pos, ele, option, op, k;
void create();
void insert();
void delete();
void display();
void rotate();
void main(void) {
	do{
	do{
		printf("enter choice number: 1. create; 2. display; 3. insert; 4. delete; 5. rotate\n");
		scanf("%d", &option);
	}while(option>5);
	
		switch(option)
		{
			case 1:
				create();
			break;
			case 2:
				display();
			break;
			case 3:
			{
				printf("enter number of insertions: \n");
				scanf("%d", &insertions);
				for(int i = 0; i < insertions; i++)
					insert();
			}
			break;
			case 4:
			{	
				printf("enter number of deletions: \n");
				scanf("%d", &deletions);
				for(int i = 0; i < deletions; i++)
					delete();
			}
			break;
			case 5:
				rotate();
			break;
			default:
				printf("invalid!\n");
			break;
		}
		printf("do you wish to continue? type 1 for yes, 2 for no\n");
		scanf("%d", &op);
	}while(op==1);
}
void create() {
	do{
		printf("enter number of elements: \n");
		scanf("%d", &n);
	}
	while(n>max);
	printf("enter the elements: \n");
	for(int i =0; i < n; i++)
	scanf("%d", &a[i]);
}
void insert(){
	do{
		printf("enter position to insert the element: \n");
		scanf("%d", &pos);
	}
	while(pos>max);
	printf("enter element to be inserted: \n");
	scanf("%d", &ele);
	for(int i = n-1; i >= pos - 1; i--)
	{
		a[i+1] = a[i];
	}
	a[pos - 1] = ele;
	n++;
}
void delete(){
	printf("enter position to delete the element: \n");
	scanf("%d", &pos);
	ele = a[pos-1];
	printf("deleted element: %d\n", ele);
	for(int i = pos-1; i < n-1; i++)  
	{
		a[i] = a[i+1];
	}
	n--;
}
void rotate(){
	printf("enter number by which you'd like to rotate the array: \n");
	scanf("%d", &k);
	if(k > n)
	{
		k = (k%n);
	}

	for(int i = 0; i < k; i++)
	{
		int temp = a[n-1];
		for(int j = n-2; j>=0; j--)
		a[j+1] = a[j];
		a[0] = temp;
	}
	display();
}
void display(){
	printf("the array is:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}
