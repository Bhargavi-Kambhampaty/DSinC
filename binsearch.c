#include <stdio.h>

int main()
{
    int se, arr[10];
    int size, i;
    printf("enter size: ");
    scanf("%d", &size);
    
    printf("enter elements: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("enter search element: ");
    scanf("%d", &se);
    
    int start = 0;
    int end = size - 1;
    int mid;
    
    while (start <= end)
    {
        mid = (start + end) / 2; 
        if (arr[mid] == se) 
        {
            printf("element found\n");
            return 0; // Exit the program after finding the element
        }
        else if (arr[mid] < se)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    
    printf("element not found\n");
    
    return 0;   
}

