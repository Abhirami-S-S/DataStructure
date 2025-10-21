#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *top = NULL;

Node *createNode(int value)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(int value)
{

    printf("Enter the value :");
    scanf("%d", &value);
    Node *newNode = createNode(value);
    Node *temp = top;
    newNode->next = temp;
    top = newNode;

    printf("\n%d pushed to stack\n", value);
}

void pop()
{

    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    Node *temp = top;
    top = top->next;
    printf("\n%d popped\n", temp->data);
    free(temp);
}

void display()
{
    Node *temp = top;
    if (top == NULL)
    {
        printf("Stack empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        printf("||\n");
        temp = temp->next;
    }
    printf("NULL\n");
}

void count()
{
    int count = 0;
    Node *temp = top;
    if (top == NULL)
    {
        printf("The count is 0\n");
        return;
    }
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("The count is %d\n", count);
}

int main()
{

    int value, choice;
    while (1)
    {
        printf("\n***Linked Stack Menu***\n");
        printf("\n1)Push an element \n2)Pop an element \n3)Display stack \n4)Stack count \n5)Exit\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            count(count);
            break;
        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
