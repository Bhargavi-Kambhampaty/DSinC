#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
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
            newnode->prev =temp;
            temp = newnode;
        }
        
    }
}

void ins_start()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data for insertion at the beginning: ");
    scanf("%d", &(newnode->data));
    newnode->next = NULL;
    newnode->prev = NULL;
    
    if(start == NULL)
    {
        start = newnode;
    }
    
    else
    {
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
}

void ins_end()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data for insertion at the end: ");
    scanf("%d", &(newnode->data));
    newnode->next = NULL;
    newnode->prev = NULL;
    
    if(start == NULL)
    {
        start = newnode;
    }
    
    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void ins_mid()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data for insertion in the middle: ");
    scanf("%d", &(newnode->data));
    newnode->next = NULL;
    newnode->prev = NULL;
    
    int pos;
    int i;
    if(start == NULL)
    {
        start = newnode;
    }
    
    else
    {
        temp = start;
        printf("enter position: ");
        scanf("%d", &pos);
        
        for(i = 0; i<pos-2; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void display()
{
    printf("Given doubly-linked list is: \n");
    temp=start;
       while(temp!=NULL)
       {
            printf(" %d<->",temp->data);
            temp=temp->next;
       }    
       printf("\n");
}
int main() {
    create();
    display();
    ins_start();
    display();
    ins_end();
    display();
    ins_mid();
    display();
    return 0;
}
