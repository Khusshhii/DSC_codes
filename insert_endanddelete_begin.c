#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node* next;
};

struct node * head= NULL;
void traverse()
{
struct node*temp=head; 
if (head==NULL)
{
printf("empty list \n");
return;
}

while(temp!=NULL)
{
printf("%d \n",temp->info);
temp=temp->next;
}

}

int insert_end(int data)
{

struct node*newnode;
struct node*cur=head;
newnode=(struct node*)malloc(sizeof(struct node));
//printf("\n enter data to be inserted \n");
//scanf("%d",&data);
newnode->info=data;
newnode->next=NULL;

if(cur==NULL)
head=newnode;

else
{
while(cur->next!=NULL)
{
cur=cur->next;
}
cur->next=newnode;
}
return 0;
}

void delete_begin()
{
struct node*temp=head;
if(head==NULL)
printf("\n empty list\n");
else
{
head=head->next;
free(temp);
//return;
}
}

int main()
{
struct node*head=NULL;
//traverse();
insert_end(22);
insert_end(33);
traverse();
delete_begin();
printf("the updated list is");
traverse();
return 0;

}