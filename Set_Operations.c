#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
void inputSet(int *set)
{
    printf("Enter the Elements (0 to %d),-1 to stop: ", SIZE - 1);
    int x;
    while (1)
    {
        scanf("%d", &x);
        if (x == -1)
            break;
        if (x >= 0 && x < SIZE)
            *set |= (1 << x);
        else
            printf("Invalid Element\n");
    }
}
void displaySet(int set)
{
    int i;
    printf("{ ");
    for (i = 0; i < SIZE; i++)
    {
        if (set & (1 << i))
            printf("%d ", i);
    }
    printf("}\n");
}

void main()
{
    int ch, setA = 0, setB = 0, result;
    printf("Enter the SetA:\n");
    inputSet(&setA);
    printf("Set A = ");
    displaySet(setA);
    printf("Enter the SetB:\n");
    inputSet(&setB);
    printf("Set B = ");
    displaySet(setB);
    while (1)
    {
        printf("\n**MENU**\n");
        printf("1.Display Sets \n2.Union\n3.Intersection\n4.Difference(A-B\n5.Difference(B-A)\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Set A : ");
            displaySet(setA);
            printf("Set B : ");
            displaySet(setB);
            break;
        case 2:
            result = setA | setB;
            printf("Union : ");
            displaySet(result);
            break;
        case 3:
            result = setA & setB;
            printf("Intersection : ");
            displaySet(result);
            break;
        case 4:
            result = setA & ~setB;
            printf("Difference (A-B): ");
            displaySet(result);
            break;
        case 5:
            result = setB & ~setA;
            printf("Difference : (B-A) ");
            displaySet(result);
            break;
        case 6:
            printf("Exiting..\n");
            exit(0);
        default:
            printf("Invalid Choice.");
        }
    }
}
