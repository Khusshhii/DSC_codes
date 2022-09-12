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
void sort()
{
    struct node *cur=head;
    struct node *prev=head;
    struct node *res;
   
    while(cur->next!=NULL)
    {
        
        
        if(cur->info < prev->info)
        {
            res->info=prev->info;
            prev->info=cur->info;
            cur->info=res->info;
        }
        prev=cur;
        cur=cur->next;
    }
}
int main()
{
    int x;
    printf("enter value of x");
    scanf("%d",&x);
    struct node *head=NULL;
    traverse();
    printf("\n");
    insert_Begin(x);
    insert_Begin(15);
    insert_Begin(260);
    insert_Begin(30);
    traverse();
    printf("sorted order is");
    sort();
    
    return 0;
}