
#include <stdio.h>

int main()
{
    int size, arr[10];
    int i, t;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    printf("enter elements: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    } 
    
    for(i = 0; i < size; i++)
    {
       t = arr[i];
       int j = i;
       
       while((j > 0) && (t < arr[j-1]))
       {
           arr[j] = arr[j-1];
           j--;
       }
       
       arr[j] = t; 
    }
    
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
    
}

