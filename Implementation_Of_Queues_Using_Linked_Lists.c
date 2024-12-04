#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* next;
};
struct node* start;
struct node* getNode(int n)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p==NULL)
    {
        return p;
    }
    p->info=n;
    p->next=NULL;
    return p;
}

void enqueue(int value)
{
    struct node* new_node=getNode(value);
    
    if(new_node==NULL)
    {
        return;
    }
    else if(start==NULL)
    {
        start=new_node;
    }
    else if(start->next==NULL)
    {
        start->next=new_node;
    }
    else
    {
        struct node* temp = start;
        while(temp->next!=NULL)
        {
            
            temp=temp->next;
        }
        temp->next=new_node;
    }
}

void dequeue()
{
    if(start==NULL)
    {
        return;
    }
    else
    {
        struct node* temp = start;
        start=temp->next;
        free(temp);
    }
}

void traverse()
{
    if(start==NULL)
    {
        return;
    }
    else
    {
        struct node* temp = start;
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }
}


void main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    traverse();
    
    dequeue();
    traverse();
}
