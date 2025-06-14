#include <stdio.h>

int partition(int A[],int lb,int ub)
{
    
    int pivot = A[lb];
    int start = lb;
    int end = ub;
    while(start<end)
    {
        while(A[start] <= pivot && start < ub)
            start++;
        while(A[end] > pivot)
            end--;
        if(start<end)
        {
            int t = A[start];
            A[start] = A[end];
            A[end] = t;
        }
    }
    int p = A[lb];
    A[lb] = A[end];
    A[end] = p;
    
    return end;
}
 
void quick_sort(int A[], int start, int end)
{
    if(start<end)
    {
        int piv = partition(A, start, end);
        quick_sort(A, start, piv-1);
        quick_sort(A, piv+1, end);
    }
}

int main() 
{
    int size, arr[10];
    int i;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    printf("enter elements: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    } 
    
    quick_sort(arr, 0, size - 1);
    
    printf("Sorted array:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    } 
    
     return 0;
}
