
#include <stdio.h>

int main()
{
    int size, arr[10];
    int i, t, min;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    printf("enter elements: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    } 
    
    for(i = 0; i < (size-1); i++)
    {
       min = i;
       
       for(int j = (i+1); j < size; j++)
       {
           if (arr[j] < arr[min])
           {
               min = j;
           }
       }
        t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }
    
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
    
}
