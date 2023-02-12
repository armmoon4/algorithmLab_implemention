#include<stdio.h>


int main()
{
    int arr[10], i, j, temp, n ;

    printf("Enter Total Numbers:" );
    scanf("%d", &n);
    printf("Enter The Elements of The Array :");
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 1 ; i < n ; i++)
    {
        temp = arr[i];
        j = i - 1 ;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp ;

    }
    printf("Sorted Array is: ");
    for(i = 0 ; i < n ; i++)
    {
        printf("%d ", arr[i]);
    }
}
