#include <stdio.h>

int main()
{
    int size, arr[10];
    int i, se;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    printf("enter elements: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("enter search element: ");
    scanf("%d", &se);
    
    int flag = 0;
    
    for(i = 0; i < size; i++)
    {
        if (se == arr[i])
        {
            flag = 1;
             break;
        }
       
    }
    
    if (flag == 1)
    {
        printf("element found");
    }
    else 
    {
        printf("element not found");
    }
    return 0;
}
