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
int search_ele()
{
    struct node * temp=head;
    int c=0;
    int n;
    printf("enter element to be searched");
    scanf("%d",&n);
    /*
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    */
    while(temp!=NULL)
    {
        if(temp ->info==n)
        {
            c=1;
            break;
        }
        temp=temp->next;
    }
    if(c==1)
    printf("found");
    else
    printf("not found");
    
    return c;
    
}

int main()
{
    int c;
    int x;
    printf("Enter values to be inserted");
    scanf("%d",&x);
    struct node *head=NULL;
    
    printf("\n");
    insert_Begin(x);
    insert_Begin(91);
    insert_Begin(20);
    traverse();
    search_ele();
    
    return 0;
}