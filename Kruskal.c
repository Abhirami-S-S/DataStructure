#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
#define INF INT_MAX
int parent[20];
int find(int i)
{
	while (parent[i]!=i)
	{
		i=parent[i];
	}
	return i;
}//find
void union_s(int i,int j)
{
	int a=find(i);
	int b=find(j);
	parent[a]=b;
}//union of set
void  main()
{
	int u[20],v[20],w[20];
	int n,e;
	int i,j,k=1,min,a,b,mincost=0;
	printf("Enter the number of Vertices:");
	scanf("%d",&n);
	printf("Enter the number of Edges:");
	scanf("%d",&e);
	printf("Enter the edges:\nu v weight\n");
	for(i=0;i<e;i++)
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);	
	}
	for(i=0;i<n;i++)
		parent[i]=i;
	printf("Edges in minimum spanning tree:\n");
	while(k<n)
	{
		min=INF;
		a=-1;
		b=-1;
		
		for(i=0;i<e;i++)
		{
			int x=find(u[i]);
			int y=find(v[i]);
			if (x!=y && w[i]<min)
			{
				min=w[i];
				a=u[i];
				b=v[i];
			}
		}
		if(a!=-1 && b!=-1)
		{
			union_s(a,b);
			printf("%d -- %d == %d\n",a,b,min);
			mincost+=min;
			k++;
		}else{
			break;
		}

	}//while
	printf("Minimum Cost of MST :%d \n",mincost);
}//main
