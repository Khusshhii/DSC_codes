#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
int counta=0,countb=0;
void insertend1(int x)
{
    struct node *newnode, *temp;
    temp=head1;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=x;
    newnode->next=NULL;
    if(head1==NULL)
    {
        head1=newnode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertend2(int x)
{
    struct node *newnode, *temp;
    temp=head2;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=x;
    newnode->next=NULL;
    if(head2==NULL)
    {
        head2=newnode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertend3(int x)
{
    struct node *newnode, *temp;
    temp=head3;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=x;
    newnode->next=NULL;
    if(head3==NULL)
    {
        head3=newnode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void delete_beg()
{
    struct node *temp;
    temp=head1;
    if(head1==NULL)
    {
        printf("deletion not possible");
        
    }
  else
  {  
   head1=head1->next;
    free(temp);
    
  }
}
void deletend()
{
    struct node *temp=head1,*prev;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void tr1()
{
    struct node *temp;
    temp=head1;
    if(head1==NULL)
    {
        printf("empty list\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d-->",temp->info);
        temp=temp->next;
        counta++;
    }
   
}
void tr2()
{
    struct node *temp;
    temp=head2;
    while(temp!=NULL)
    {
        printf("%d-->",temp->info);
        temp=temp->next;
        countb++;
    }
    
}
void tr3()
{
    struct node *temp;
    temp=head3;
    while(temp!=NULL)
    {
        printf("%d-->",temp->info);
        temp=temp->next;
        
    }
}
void sort()
{
    struct node *temp,*adv=NULL;
    temp=head1;
    int flag;
    while(temp!=NULL)
    {
        adv=temp;
        while(adv!=NULL)
        {
            if(temp->info>adv->info)
            {
                flag=temp->info;
                temp->info=adv->info;
                adv->info=flag;
            }
            adv=adv->next;
        }
        temp=temp->next;
    }

}
void deleten(int n)
{
    int i;
    struct node *temp,*prev;
    temp=head1;
    prev=head1;
    if(n==1)
    {
        delete_beg();
    }
    else if (n==counta)
    {
        deletend();
    }
    else
    {
    for(i=1;i<n;i++)
    {
        prev=temp;
        temp=temp->next;
        prev->next=temp->next;
        free(temp);
    }
    }
}
void splodev()
{
    struct node *temp=head1,*prev;
    int n,a[100],b[100],i=0,j=0,count1=0,count2=0;
    
    while(temp!=NULL)
    {
        if(temp->info%2==0)
        {
            a[i]=temp->info;
            i++;
            count1++;
        }
        else
        {
            b[j]=temp->info;
            j++;
            count2++;
        }
        temp=temp->next;
    }
    for(i=0;i<counta;i++)
    {
        delete_beg();
    }
    for(i=0;i<count1;i++)
    {
        insertend1(a[i]);
    }
    for(j=0;j<count2;j++)
    {
        insertend2(b[j]);
    }   
}
void ctthird()
{
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1!=NULL)
    {
        
        while(temp2!=NULL)
        {
            if(temp1->info==temp2->info)
            {
                insertend3(temp1->info);
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
        temp2=head2;
    }
}
void merge()
{
    if(head1==NULL)
    {
        tr2();
    }
    else if(head2==NULL)
    {
        tr1();
    }
    else
    {
        struct node *temp1,*temp2;
        temp1=head1;
        temp2=head2;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp2;
    }
}
void main()
{
    int n,i,choice;
    for(;;)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            scanf("%d",&n);
            insertend1(n);
            break;
            case 2:
            tr1();
            break;
            case 3:
            scanf("%d",&n);
            insertend2(n);
            break;
            case 4:
            tr2();
            break;
            case 5:
            merge();
            sort();
            break;
            case 6:
            deleten(1);
            break;
            case 7:
            deletend();
            break;
            case 8:
            splodev();
            break;
            case 9:
            ctthird();
            break;
            case 10:
            tr3();
            break;
            default:
            exit(1);
        }
    }
}