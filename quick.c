#include <stdio.h>
int a[20];
int partition(int l, int r)
{
    int pivot, i, j, temp;
    pivot = l;
    i = l + 1;
    j = r;
    while (i <=j)
    {
        while (a[i] < a[pivot] && i <= r)
        {
            i++;
        }
        while (a[j] > a[pivot] && j >= l)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    if (i > j)
    {
        temp = a[j];
        a[j] = a[pivot];
        a[pivot] = temp;
    }
    return j;
}
void quick_sort(int l, int r)
{
    if(l<r){
    int p;
    p = partition(l, r);
    quick_sort(l, p - 1);
    quick_sort(p + 1, r);
    }
}
void main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    printf("Enter the array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quick_sort(0, n - 1);
    printf("Array:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
