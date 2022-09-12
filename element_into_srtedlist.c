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

int insert_begin(int data)
{
struct node*newnode;
struct node*cur=head;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->info=data;
//cur=cur->next;
newnode->next=head;
head=newnode;
return 0;
}

/*
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
*/


/*
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
*/


int enter_ele(int data)
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
struct node*cur=head;
struct node*prev=head;
struct node*adv=cur->next;
while(adv!=NULL)
{
    if(data > cur->info && data < adv->info)
        {
            newnode->info=data;
            newnode->next=adv;
            cur->next=newnode;

        }
cur=adv;
adv=adv->next;
}

return 0;
}

int main()
{
struct node*head=NULL;
traverse();
insert_begin(100);
insert_begin(97);
insert_begin(88);
insert_begin(50);


enter_ele(89);
//insert_end(22);
//insert_end(33);
traverse();
//delete_begin();
//printf("the updated list is");
//traverse();
return 0;

}