#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *head=NULL;
int count=0;
void insertbeg(int n)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=n;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
        return;
    }
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;
}
void insertbefore()
{
    int n,x;
    printf("Enter the number before which insertion has to take place\n");
    scanf("%d",&n);
    printf("Enter the number to be inserted\n");
    scanf("%d",&x);
    struct node *temp,*newnode,*old;
    temp=head;
    while(temp!=NULL && temp->info!=n)
    {
        //old=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("element not found,unsuccesful insertion\n");
        return;
        
    }
    else if(temp->info==head->info)
    {
        insertbeg(x);
    }
    else

    {
        old=temp->prev;
        printf("%d",old->info);
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->info=x;
        newnode->next=temp;
        /*
        newnode->prev=temp->prev;
        temp->prev->next=newnode;
        temp->prev=newnode;*/
        old=temp->prev;
        newnode->prev=old;
        old->next=newnode;
        temp->prev=newnode;
        printf("\n Inserted successfully");

    }
}
void deletemid()
{
    struct node *temp=head,*old;
    int i, mid;
    mid=count/2.0;
    if(count%2==0 )
    {
        for(i=1;i<mid;i++)
        {
            old=temp;
            temp=temp->next;
        }
    }
    
    else
    {
        for(i=1;i<=mid;i++)
        {
            old=temp;
            temp=temp->next;
        }

    }
    old->next=temp->next;
    free(temp);
    
}
void traverse()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("empty list");
        return;
    }
    while(temp!=NULL)
    {
        printf("<--%d-->",temp->info);
        temp=temp->next;
        count++;
    }
}
void main()
{
    int n,choice;
    for(;;)
    {
        printf("\n1.Insert begin\n2.Traverse\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the number");
            scanf("%d",&n);
            insertbeg(n);
            break;
            case 2:
            traverse();
            break;
            case 3:
            insertbefore();
            break;
            case 4:
            deletemid();
            break;
            default:
            exit(0);
        }
    }
}