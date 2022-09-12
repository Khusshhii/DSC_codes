// write a c prog to implement student information stored in a bst based on the usn ans search for the student for the given usn.

#include<stdio.h>
#include<stdlib.h>
struct BST
{
    struct BST *left;
    int USN;
    char name[10];
    char dept[4];
    struct BST *right;
};
struct BST *root=NULL;
void insert()
{
    struct BST *newnode,*temp,*prev;
    temp=root;
    newnode=(struct BST *)malloc(sizeof(struct BST));
    printf("enter USN,name and dept\n");
    scanf("%d",&newnode->USN);
    scanf("%s",&newnode->name);
    scanf("%s",&newnode->dept);
    if(root==NULL)
    {
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
        return;
    }
    while(temp!=NULL)
    {
        prev=temp;
        if(temp->USN<newnode->USN)
        temp=temp->right;
        else
        temp=temp->left;
    }
    if(prev->USN<newnode->USN)
    prev->right=newnode;
    else
    prev->left=newnode;

}
void search()
{
    int USN;
    printf("enter the USN of student who needs to be searched");
    scanf("%d",&USN);
    if(root==NULL)
    {
        printf("empty tree\n");
        return;
    }
    struct BST *temp=root;
    while(temp!=NULL && temp->USN!=USN)
    {
        if(USN>temp->USN)
        temp=temp->right;
        else
        temp=temp->left;
    }
    if(temp==NULL)
    printf("Student Not Found\n");
    else
    {
        printf("Details of the student are:\n");
        printf("USN:%d\n Name: %s\n Dept:%s\n ",temp->USN,temp->name,temp->dept);
    }
}
void main()
{
    int choice;
    for(;;)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert();
            break;
            case 2:
            search();
            break;
            default:
            exit(0);
        }
    }
}