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
 
   int n,x;
    printf("Enter digit 0 for traverse and 1 for insert_Begin\n");
    scanf("%d",&n);
   
    switch(n)
    {
        case 0:traverse();
               break;
        case 1:printf("Enter value to be inserted \t");
               scanf("%d",&x);
               insert_Begin(5);
               insert_Begin(x);
               break;
    }
   
    traverse();
    return 0;
}