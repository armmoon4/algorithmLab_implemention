#include<stdio.h>
int main(){
   /* Here i & j for loop counters, temp for swapping,
    * count for total number of elements, number[] to
    * store the input numbers in array. You can increase
    * or decrease the size of number array as per requirement
    */
   int i, j, count, temp, number[25];
   printf("Enter the numbers of elements: ");
   scanf("%d",&count);
   printf("Enter the numbers in the array:");
   // This loop would store the input numbers in array
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);
   // Implementation of insertion sort algorithm
   for(i=1;i<count;i++){
      temp=number[i];
      j=i-1;
      while((temp<number[j])&&(j>=0)){
         number[j+1]=number[j];
         j=j-1;
      }
      number[j+1]=temp;
   }
   printf("After sorting elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
   return 0;
}
