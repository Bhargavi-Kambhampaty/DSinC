#include <stdio.h>

int main()
{
    int size,arr[10];
    int i, t, j;
    printf("enter size:");
    scanf("%d", &size);
    
    printf("enter elements:");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < size; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    
    for(i = 0; i<size;i++)
    {
        printf("%d ", arr[i]);
    }    
    return 0;   
}    
