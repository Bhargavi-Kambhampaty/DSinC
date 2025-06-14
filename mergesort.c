
#include <stdio.h>

void merge(int b[], int beg, int mid, int end)
{
    
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int larr[n1], rarr[n2];
    
    for (i = 0; i < n1; i++)
    {
        larr[i] = b[beg + i];
    }
    
    for (j = 0; j < n2; j++)
    {
        rarr[j] = b[mid + 1 +j];
    }
    
    i = 0;
    j = 0; 
    k = beg;
    
    while ((i < n1) && (j < n2))
    {
        if (larr[i] <= rarr[j])
        {
            b[k] = larr[i];
            i++;
        }
        
        else
        {
            b[k] = rarr[j];
            j++;
        }
        
        k++;
    }
    
    while (i < n1)
    {
        b[k] = larr[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        b[k] = rarr[j];
        j++;
        k++;
    }
}

void mergesort(int A[], int start, int end)
{
    if (start < end)
    {
        int mid = (end + start)/ 2 ;
        mergesort(A, start, mid);
        mergesort(A, mid + 1, end);
        merge(A, start, mid, end);
    }

}

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
    
    mergesort(arr, 0, size - 1);
    
    for(int j = 0; j<size; j++)
    {
        printf("%d ", arr[j]);
    }
    return 0;
}

