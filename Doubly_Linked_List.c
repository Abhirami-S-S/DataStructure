#include<stdio.h>
#include<stdlib.h>
typedef struct Nodes Node;
struct Nodes{
	int data;
	Node* prev;
	Node* next;
};
Node* start=NULL;
Node* create()
{
	int v;
	Node *newnode=(Node*)malloc(sizeof(Node));
	printf("Enter the Value:");
	scanf("%d",&v);
	newnode->data=v;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}//create
void insertB()
{
	Node *newnode=create();
	newnode->prev=NULL;
	newnode->next=start;
	if(start==NULL)
	{
		start=newnode;
		return;
	}//if
	start->prev=newnode;
	start=newnode;
	printf("%d is inserted at Beginning.\n",newnode->data);
	
}//insert at beginning
void insertE()
{
	Node *newnode=create();
	if(start==NULL)
	{
		start=newnode;
		return;
	}//if
	Node *temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}//while
	temp->next=newnode;
	newnode->prev=temp;
	printf("%d is inserted at End.\n",newnode->data);
}//insert at end
void displayB()
{
	Node* temp=start;
	if(start==NULL)
	{
		printf("List is Empty.\n");
		return;
	}//if
	printf("Doubly Linked List from Beginning:\n");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		if(temp->next!=NULL)
		{
			printf("<->");
		}
		temp=temp->next;
	}//while
	printf("\n");
}//display from beginning
void displayE()
{
	Node* temp=start;
	if(start==NULL)
	{
		printf("List is Empty.\n");
		return;
	}//if
	printf("Doubly Linked List from End:\n");
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}//while
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		if(temp->prev!=NULL)
		{
			printf("<->");
		}
		temp=temp->prev;
	}//while
	printf("\n");
}//display from end
void deleteB()
{
	Node* temp=start;
	if(start==NULL)
	{
		printf("List is Empty\n");
		return;
	}//if
	start=temp->next;
	if(temp->next!=NULL)
	{
		start->prev=NULL;
	}//if
	printf("%d is deleted.\n",temp->data);
	free(temp);
}//delete from beginning
void deleteE()
{
	Node* temp=start;
	if(start==NULL)
	{
		printf("List is Empty\n");
		return;
	}//if
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}//if
	if(temp->prev!=NULL)
	{
		temp->prev->next=NULL;
	}else
	{
		start=NULL;
	}
	printf("%d is deleted.\n",temp->data);
}//delete from end
void count()
{
	int c=0;
	Node* temp=start;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	printf("Count of Elements in the List = %d\n",c);
}//count
void main()
{
	int ch;
	while(1)
	{
		printf("\n**---Doubly Linked List---**\n1.Insert At Beginning\n2.Insert At End\n3.Delete From Beginning");
		printf("\n4.Delete From End\n5.Display from Beginning\n");
		printf("6.Display From End\n7.Count the Elememts\n8.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insertB();
				break;
			case 2:
				insertE();
				break;
			case 3:
				deleteB();
				break;
			case 4:
				deleteE();
				break;
			case 5:
				displayB();
				break;
			case 6:
				displayE();
				break;
			case 7:
				count();
				break;
			case 8: 
				printf("Exiting.........\n");
				exit(0);
			default:
				printf("Invalid choice\n");
				
		}//switch
	}//while
}//MAIN























