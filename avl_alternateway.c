#include<stdio.h>
#include<stdlib.h>
struct AVLnode
{
    struct AVLnode*left;
    struct AVLnode*right;
    int data;
    int BF;
};
struct AVLnode*root=NULL;
struct AVLnode*newnode(int key)
{
    struct AVLnode*cur;
    cur=(struct AVLnode*)malloc(sizeof(struct AVLnode));
    cur->left=cur->right=NULL;
    cur->data=key;
    cur->BF=0;
}
int height(struct AVLnode*n)
{
    int ldepth,rdepth;
    if(n==NULL)
        return -1;
    ldepth=height(n->left);
    rdepth=height(n->right);
    if(ldepth>rdepth)
        return (ldepth+1);
    else
        return (rdepth+1);
}
struct AVLnode*rightrotate(struct AVLnode*y)
{
    struct AVLnode*x=y->left;
    struct AVLnode*T2=x->right;
    x->right=y;
    y->left=T2;
    x->BF=height(x->left)-height(x->right);
    y->BF=height(y->left)-height(y->right);
    return x;
}
struct AVLnode*leftrotate(struct AVLnode*y)
{
    struct AVLnode*x=y->right;
    struct AVLnode*T2=x->left;
    x->left=y;
    y->right=T2;
    x->BF=height(x->left)-height(x->right);
    y->BF=height(y->left)-height(y->right);
    return x;

}
struct AVLnode*insert(struct AVLnode*n,int key)
{
    int balance;
    if(n==NULL)
        return newnode(key);
    else if(key<n->data)
        n->left=insert(n->left,key);
    else if(key>n->data)
        n->right=insert(n->right,key);
    else
        return n;
    n->BF=height(n->left)-height(n->right);
    balance=n->BF;
    if(balance>1&&n->left->data>key)
        return rightrotate(n);
    if(balance<-1&&n->right->data<key)
        return leftrotate(n);
    if(balance>1&&n->left->data<key)
    {
        n->left=leftrotate(n->left);
        return rightrotate(n);
    }
    if(balance<-1&&n->right->data>key)
    {
        n->right=rightrotate(n->right);
        return leftrotate(n);
    }
    return n;
}
void inorder(struct AVLnode*cur)
{
    if(cur!=NULL)
    {
        inorder(cur->left);
        printf("no.%d   bf.%d\n",cur->data,cur->BF);
        inorder(cur->right);
    }
}
int main()
{
    int input,data,key;
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Inorder\n");
        printf("3.Exit\n");
        scanf("%d",&input);
        if(input==1)
        {
            printf("Enter value of element:");
            scanf("%d",&data);
            root=insert(root,data);}
        else if(input==2)
            inorder(root);
        else if(input==3)
            break;
        else
            printf("Invalid\n");
    }
    return 0;
}