#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node * next;
};
struct node *head = NULL;
void traverse()
{
    struct node * temp=head;
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
/*
void create()
{
    int data, n;
    printf("Enter value of n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",data);
        insert_Begin(data);
        printf("/n");

    }
    traverse();
}
*/
void insert_Begin(int x)
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->info=x;
    new_node->next=head;
    head=new_node;
}
int main()
{
    struct node *head=NULL;
    traverse();
    printf("\n");
    int data;
    insert_Begin(10);
    insert_Begin(15);
    insert_Begin(20);
    traverse();
    return 0;
}