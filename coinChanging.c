#include<stdio.h>
int main()
{
    int a[100], b[100] , count,  i, j,  n, sum, num, temp, value;
    count = 0 ;
    printf("Enter the numbers of coin:");
    scanf("%d", &n);
    printf("Enter the coins : ");
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 0 ; i < n-1 ; i++)
    {
        for(j = 0 ; j < n-i-1 ; j++)
        {
            if(a[j] < a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Enter the amount:");
    scanf("%d" , &value);
    for(i = 0 ; i < n ; i++) {
        while(value >= a[i])
        {
            value -= a[i];
            b[count] = a[i];
            count++;
        }
        if(value == 0)
            break;
    }
    printf("Minimum Numbers of coin needed: ");
    printf("%d" , count);
    printf("Coin still need: %d" , value);


}
