#include <stdio.h>
int partition (int a[], int l, int r)
{
    int pivot = a[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i+1];
    a[i+1] = a[r];
    a[r] = t;
    return (i + 1);
}

void quick(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quick(a, l, p - 1);
        quick(a, p + 1, r);
    }
}

void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
int main()
{
    int a[] = { 24, 9, 29, 14, 19, 27 };
    int n = sizeof(a) / sizeof(a[0]);
    printf("Before sorting array elements: \n");
    printArr(a, n);
    quick(a, 0, n - 1);
    printf("After sorting array elements: \n");
    printArr(a, n);

    return 0;
}
