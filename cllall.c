
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*start = NULL, *newnode = NULL, *temp = NULL;

void create()
{
    int size, i, data;
    
    printf("enter size: ");
    scanf("%d", &size);
    
    for(i = 0; i < size; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &(newnode->data));
        newnode->next = NULL;
        
        if(start == NULL)
        {
            start = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        
    }
}

void display()
{
    temp=start;
       while(temp!=NULL)
       {
            printf(" %d->",temp->data);
            temp=temp->next;
       }    
       printf("\n");
}

void count()
{
    int count = 0;
    temp = start;
    while(temp != NULL)
    {
        count +=1;
        temp = temp->next;
    }
    printf("the number of nodes is %d\n", count);
}

void search()
{
    int se;
    printf("enter search element: ");
    scanf("%d", &se);
    
    int flag = 0;
    temp = start;
    
    while(temp != NULL)
    {
        if (se == temp->data)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    
    if(flag == 1)
    {
       printf("elment found");
    }
    else
    {
        printf("element not found");
    }
}
int main()
{
    create();
    display();
    count();
    search();

    return 0;
}

