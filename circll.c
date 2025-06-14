#include <stdio.h>
#include <stdlib.h>

struct node
{    int data;
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
            newnode->next = start;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->next = start;
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
    
    if(start == NULL)
    {
        start = newnode;
        newnode->next = start;
        temp = newnode;
    }
    
    else
    {
        temp = start;
        while((temp->next) != start)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = start;
        start = newnode;
    }
}

void del_start()
{
    if(start == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        temp = start;
        while(temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = start;
        start = start->next;
    }
}

void display()
{
    temp = start;
    printf("Given Linked list is: ");
    do{
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    while(temp!= start);
    printf("\n");
}

int main() {
    create();
    display();
    ins_start();
    display();
    printf("after deletion at the beginning: ");
    del_start();
    display();
    
    return 0;
}

