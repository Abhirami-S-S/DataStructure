#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node node;
struct Node{
	int data;
	node *left;
	node *right;
};
node *root=NULL;
/*struct queue{
	node *data[100];
	int f,r;
};
*/
int c=0;
void insert()
{
	node *temp,*newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("Enter the value :");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
		printf("%d IS INSERTED AS ROOT NODE.\n",newnode->data);
		c++;
	}else{
		node* queue[100];
		int f=0,r=0;
		queue[r]=root;
		while(f<=r)
		{
			temp=queue[f++];
			if(temp->left==NULL)
			{
				temp->left=newnode;
				printf("%d is inserted at left of %d.\n",newnode->data,temp->data);
				c++;
				return;
			}else
				queue[++r]=temp->left;
			if(temp->right==NULL)
			{
				
				temp->right=newnode;
				printf("%d is inserted at right of %d.\n",newnode->data,temp->data);
				//printf("%d is inserted at right of %d.    .\n",newnode->data,temp->data);
				c++;
				return;
			}else
				queue[++r]=temp->right;
		}//while
	}//else
}//insert
/*void printing()
{
	int m,tree[100][100],i;
	for(i=4;i>=0;i--)
	{
		if(h<=(pow(2,i)))
		{
			m=pow(2,i);
			break;
		}
	}	
}*/
void preordert(node* nodes)
{
	if(nodes==NULL)
	{
		return;
	}
	printf("%d ",nodes->data);
	preordert(nodes->left);
	preordert(nodes->right);
}//preorder traversal
void preorder()
{
	if(root==NULL)
	{
		printf("It is empty\n");
		return;
	}//if
	printf("Preorder Traversal:");
	preordert(root);
}
void postordert(node* nodes)
{
	if(nodes==NULL)
	{
		return;
	}
	postordert(nodes->left);
	postordert(nodes->right);
	printf("%d ",nodes->data);
}//postorder traversal
void postorder()
{
	if(root==NULL)
	{
		printf("It is empty\n");
		return;
	}//if
	printf("Inorder Traversal:");
	postordert(root);
}
void inordert(node* nodes)
{
	if(nodes==NULL)
	{
		return;
	}
	inordert(nodes->left);
	printf("%d ",nodes->data);
	inordert(nodes->right);
}//inorder traversal
void inorder()
{
	if(root==NULL)
	{
		printf("It is empty\n");
		return;
	}//if
	printf("Inorder Traversal:");
	inordert(root);
}
void delete()
{
	int key,f1=0;
	printf("Enter the value to delete:");
	scanf("%d",&key);
	while(1)
	{
		node* queue[100];
		int f=0,r=0;
		queue[r]=root;
		node *temp,*keyNode=NULL,*lastNode=NULL,*parentLast=NULL;
		while(f<=r)
		{
			temp=queue[f++];
			if(temp->data==key && keyNode==NULL)
			{
				keyNode=temp;
			}
			if(temp->left)
			{
				parentLast=temp;
				queue[++r]=temp->left;
			}
			if(temp->right)
			{
				parentLast=temp;
				queue[++r]=temp->right;		
			}
			lastNode=temp;
		}//while
		if(keyNode==NULL)
			break;
		keyNode->data=lastNode->data;
		if(parentLast!=NULL)
		{
			if(parentLast->right==lastNode)
				parentLast->right=NULL;
			else if(parentLast->left==lastNode)
				parentLast->left=NULL;
		}else{
			root=NULL;
		}
		free(lastNode);
		f1++;
	}//while
	if(f1)
		printf("%d is deleted Successfully.\n",key);
	else
		printf("%d is not found.\n",key);
	
}
void main()
{
	int ch,value;
	while(1)
	{
		printf("\n--Binary Tree Menu--\n1.Insert\n2.Delete");
		printf("\n3.Inorder Traversal\n");
		printf("4.Preorder Traversal\n5.Postorder Traversal\n");
		printf("6.exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				if(root==NULL){
					printf("Tree is Empty.\n");
				}else if(root->left==NULL && root->right==NULL)
				{
					node *temp=root;
					printf("Enter the value to delete:");
					scanf("%d",&value);
					if(temp->data!=value)
					{
						printf("%d is not found.\n",value);
					}else{
						printf("%d is deleted Successfully.\n",value);
						free(temp);
						root=NULL;
					}
				}else{
					delete();
				}
				break;
			case 3: 
				inorder();
				break;
			case 4: 
				preorder();
				break;
			case 5: 
				postorder();
				break;
			case 6:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}//switch
	}
}
