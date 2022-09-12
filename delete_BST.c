#include <stdio.h>
#include<stdlib.h>
struct BSTnode
{
    struct BSTnode* left;
    int data;
    struct BSTnode*right;
};
struct BSTnode*root=NULL;

void insert(int item)
{
struct BSTnode*cur=root;
struct BSTnode*prev;
struct BSTnode*new_node=(struct BSTnode*)malloc(sizeof(struct BSTnode));
new_node->data=item;
new_node->left=NULL;
new_node->right=NULL;
if(root==NULL)
{
    root=new_node;
    return;
}
while(cur!=NULL)
{
    prev=cur;
    if(cur->data<item)
    cur=cur->right;
    else
    cur=cur->left;
}

if(prev->data<item)
prev->right=new_node;
else
prev->left=new_node;
}


struct BSTnode* findMin(struct BSTnode *r)
{
    while(r->left!=NULL)
    r=r->left;
    return r;
}

struct BSTnode* deleteNode(struct BSTnode *r,int key)
{
    struct BSTnode *temp;
    if(r==NULL)
    return NULL;
    if(r->data > key)
    r->left=deleteNode(r->left,key);
    else if(r->data < key)
    r->right=deleteNode(r->right,key);
    else
    {
        if(r->left==NULL && r->right==NULL)
        {
        free(r);
        return NULL;
        }
        else if(r->left==NULL && r->right!=NULL)
        {
            temp=r->right;
            free(r);
            return temp;
        }
        else if(r->right==NULL && r->left!=NULL)
        {
            temp=r->left;
            free(r);
            return temp;
        }
        else
        {
            temp=findMin(r->right);
            r->data=temp->data;
            r->right=deleteNode(r->right,temp->data);
        }
    }
    return r;
}



int main()
{
   int ele,ch,h;
   while(1)
   {
       printf("\nBST\n1. Inserting into BST\n2. Delete \n3. exit\n");
       scanf("%d",&ch);
       
       switch(ch)
       {
           case 1: printf("Enter the element to be inserted\n");
                   scanf("%d",&ele);
                   insert(ele);
                   break;
                   
           case 2:printf("Enter the value to be deleted : ");
                  scanf("%d",&h);
                  root=deleteNode(root,h);
                  printf("%d is deleted",h);
                  break;
                  
         
           case 3:exit(0);
            
            default:printf("INVALID input\n");
       }
   }
   return 0;
}