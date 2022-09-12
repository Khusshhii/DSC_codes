#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node * next;
};
struct node *head = NULL;
void peek()
{
    struct node *temp=head;
    /*
    if(head==NULL)
    {
        printf("Empty list /n");
        return;
    }
    */
    while(temp!=NULL)
    {
        printf("%d \t",temp->info);
        temp=temp->next;
    }
}
void push(int x)
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->info=x;
    if(head==NULL)
    {
     
        new_node->next= NULL;
        head=new_node;
        return;
    }
    new_node->next=head;
    head=new_node;

}
void pop()
{
struct node*temp=head;
if(head==NULL)
{
printf("\n empty list \n");
return;
}

head=head->next;
free(temp);
//return;

}
int main()
{
    while(1)
    {
        int n,x;
        printf("Enter digit 0 for peek and 1 for push 2 for popping\n");
        scanf("%d",&n);
   
        switch(n)
        {
            case 0:peek();
               break;
            case 1:printf("Enter value to be inserted \t");
               scanf("%d",&x);
               //push(5);
               push(x);
               
               break;
            case 2:pop();
               break;
            default:exit(1);
        }
   
        
    }
    return 0;
}