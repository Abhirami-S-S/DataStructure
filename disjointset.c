#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int parent[MAX];
void makeset(int n)
{
	for(int i=0;i<n;i++)
		parent[i]=i;
	printf("Disjoint Sets are created\n");
}//makeSet
int find(int x)
{
	if(parent[x]!=x){
		parent[x]=find(parent[x]);
	}
	return parent[x];
}//find
void unionSet(int u,int v)
{
	int parent_u=find(u),parent_v=find(v);
	if(parent_u!=parent_v)
	{
		parent[parent_v]=parent_u;
		printf("Union Done\n");
	}else{
		printf("Same set\n");	
	}
}//unionSet
void display(int n)
{
	printf("N : P\n-----\n");
	for(int i=0;i<n;i++)
		printf("%d : %d \n",i,find(i));
}//display
void main()
{
	int n,ch,a,b;
	printf("Enter no of disjoint set:");
	scanf("%d",&n);
	makeset(n);
	while(1)
	{
		printf("\n--DISJOINT MENU --\n1.Display\n2.Find\n3.Union Of Set\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				display(n);
				break;
				
			case 2:
				printf("Enter the element:");
				scanf("%d",&a);
				printf("N : P\n-----\n%d : %d",a,find(a));
				break;
				
			case 3:
				printf("Enter the pair to perform union:");
				scanf("%d %d",&a,&b);
				unionSet(a,b);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice.\n");
				
		}//switch
	}//while
	
}//main



