#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node * next;
};
struct node *head=NULL;
void traverse()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
}
void insert_Begin(int x)
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->info=x;
    new_node->next=head;
    head=new_node;
}

void minval()
{
  struct node * temp=head;
  int min=0;
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    while(temp!=NULL)
    {
        if(temp->info < min)
        {
            min=temp->info;
            temp=temp->next;
            
        }
    }
    printf("%d The min value is",min);
}

int main()
{
    int c;
    struct node *head=NULL;
    traverse();
    printf("\n");
    insert_Begin(10);
    insert_Begin(15);
    insert_Begin(20);
    insert_Begin(30);
    traverse();
    minval();
    
    return 0;
}