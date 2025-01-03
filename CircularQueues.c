#include<stdio.h>
# define MAX 10

int a[MAX];
int front=-1;
int rear=-1;

void enqueue(int n)
{
    if(rear==MAX-1)
    {
        printf("Queue is full");
        return;
    }
    rear=(rear+1)%MAX;
    a[rear]=n;
    if(front==-1)
    {
        front++;
    }
}

int dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty");
        return -1;
    }
    if(front==rear)
    {
        int temp=a[front];
        front=-1;
        rear=-1;
        return temp;
    }
    int temp=a[front];
    front=(front+1)%MAX;
    return temp;
}

void display()
{
    if(front==-1)
    {
        printf("Queue is empty");
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",a[i]);
    }
}

void main()
{
    int choice;
    do
    {
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: int n;
                    printf("Value to be inserted : ");
                    scanf("%d",&n);
                    enqueue(n);
                    break;
            case 2: int temp=dequeue();
                    printf("Value deleted : %d\n",temp);
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting...");
                    break;
            default: printf("Invalid choice");
                     break;
        }
    }while(choice!=4);
}
