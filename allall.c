#include <stdlib.h>
#include <stdio.h>

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

void start_del()
{
    if(start == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        start = start->next;
    }
}

void end_del()
{
   if(start == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        temp = start;
        while(temp->next->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

void middle_del()
{
    temp = start;
    if(start == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        int i, pos;
        printf("enter position: ");
        scanf("%d", &pos);
        
        for(i =0; i<pos-2; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}

void display()
{
    printf("Given linked list is: \n");
    temp=start;
       while(temp->next!=start)
       {
            printf(" %d->",temp->data);
            temp=temp->next;
       }    
       printf("\n");
}

void display1()
{
    printf("Given linked list is without first element: \n");
    temp=start;
       while(temp->next!=start)
       {
            printf(" %d->",temp->data);
            temp=temp->next;
       }    
       printf("\n");
}

void display2()
{
    printf("Given linked list without last element is: \n");
    temp=start;
       while(temp->next!=start)
       {
            printf(" %d->",temp->data);
            temp=temp->next;
       }    
       printf("\n");
}

void display3()
{
    printf("Given linked list without the positional element is: \n");
    temp=start;
       while(temp->next!=start)
       {
            printf(" %d->",temp->data);
            temp=temp->next;
       }    
       printf("\n");
}

int main() {
    create();
    display();
    start_del();
    display1();
    end_del();
    display2();
    middle_del();
    display3();
    return 0;
}
