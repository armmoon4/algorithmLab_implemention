#include <stdio.h>
void merge(int arr[], int l[], int left_size, int r[], int right_size)
{
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size)
    {
        if (l[i] <= r[j])
        {
            arr[k++] = l[i++];
        }
        else
        {
            arr[k++] = r[j++];
        }
    }

    while (i < left_size)
    {
        arr[k++] = l[i++];
    }

    while (j < right_size)
    {
        arr[k++] = r[j++];
    }
}
void merge_sort(int arr[], int size)
{
    if (size < 2)
    {
        return;
    }

    int mid = size / 2;
    int left[mid], right[size - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }
    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}

int main()
{
    int arr[100], size;
    printf("Enter the numbers of elements");
    scanf("%d", &size);
    printf("Enter The elements of the array ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, size);
    printf("Sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
