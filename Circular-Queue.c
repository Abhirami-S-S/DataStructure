#include<stdio.h>
#include<stdlib.h>
#define N 5
int r=-1,f=-1;
int cq[N];
void enqueue()
{
	int value;
	if((f==0 && r==N-1)||(f==(r+1)%(N)))
	{
		printf("Circular Queue Overflow..\n");
		return;
	}
	printf("Enter the value:");
	scanf("%d",&value);
	if(f==-1)
	{
		f=0;
		r=0;
	}else if(r==N-1){
		r=0;
	}else{
		r++;
	}
	cq[r]=value;
	printf("%d is enqueued.\n",value);
}//enqueue
void dequeue()
{
	if(f==-1)
	{
		printf("Circular Queue Underflow..\n");
		return;
	}
	printf("%d is dequeued.\n",cq[f]);
	if(f==r)
	{
		f=r=-1;
	}else if(f==N-1){
		f=0;
	}else{
		f++;
	}
	
}//dequeue
void display()
{
	int i;
	if(f==-1)
	{
		printf("Circular Queue is Empty..\n");
		return;
	}
	if(r>=f)
	{
		for(i=f;i<=r;i++)
			printf("%d ",cq[i]);
	}else
	{
		for(i=f;i<N;i++)
			printf("%d ",cq[i]);
		for(i=0;i<=r;i++)
			printf("%d ",cq[i]);
	}//else
	printf("\n");
}//display
int count()
{
	int i,c=0;
	if(f==-1)
		return c;
	if(r>=f)
	{
		for(i=f;i<=r;i++)
			c++;
	}else
	{
		for(i=f;i<N;i++)
			c++;
		for(i=0;i<=r;i++)
			c++;
	}//else
	return c;
}//count
void main()
{
	int ch;
	while(1)
	{
		printf("\n--CIRCULAR QUEUE--\n1.Enqueue\n2.Dequeue\n3.Display");
		printf("\n4.Count\n5.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Count of Elements = %d\n",count());
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid choice.\n");
		}//switch
		
	}//while
}//main

