#include<stdio.h>
#include<stdlib.h>
struct BST
{
    struct BST *left;
    int data;
    struct BST *right;
};
struct BST *root=NULL;
int n,pre[20],t[20],ti=0;
int exists(int d)
{
    int i,c=0;
    for(i=0;pre[i]!='\0';i++)
    if(pre[i]==d)
    {
    c++;
    break;
    }
    return c;
}
int already(struct BST *r,int d)
{
    int i,c=0;
    for(i=0;i<ti;i++)
    if(t[i]==d)
    c++;
    t[ti]=d;
    ti++;
    return c;
}
void insert(int d)
{
    if(!exists(d))
    return;
    if(already(root,d))
    return;
    struct BST *new1,*cur=root,*prev;
    new1=(struct BST *)malloc(sizeof(struct BST));
    new1->left=new1->right=NULL;
    new1->data=d;
    if(cur==NULL)
    {
        root=new1;
        return;
    }
    while(cur!=NULL)
    {
        prev=cur;
        if(cur->data > d)
        cur=cur->left;
        else
        cur=cur->right;
    }
    if(prev->data > d)
    prev->left=new1;
    else
    prev->right=new1;
}
void postorder(struct BST *r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d->",r->data);
    }
}
void preorder(struct BST *r)
{
    if(r!=NULL)
    {
        printf("%d->",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
void inorder(struct BST *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d->",r->data);
        inorder(r->right);
    }
}
int find(int a,int arr[])
{
    int i;
    for(i=0;arr[i]!='\0';i++)
    if(arr[i]==a)
    return i;
}
void slice(int x[],int s,int e,int ar[])
{
    int i=0,c=s;
    for(i=0;c<=e;i++)
    {
        ar[i]=x[c];
        c++;
    }
}
void getInorder(int in[],int pre[])
{
    int i,j,temp,c=0;
    for(i=0;pre[i]!='\0';i++)
    {
    c++;    
    in[i]=pre[i];
    }
    for(i=0;i<c;i++)
    {
        for(j=i+1;j<c;j++)
        if(in[j]<in[i])
        {
            temp=in[i];
            in[i]=in[j];
            in[j]=temp;
        }
    }
}
int before(int a,int aa[])
{
    int c=0,i;
    for(i=0;aa[i]!=a;i++)
    c++;
    return c;
}
int after(int a,int aa[])
{
    int c=0,i;
    for(i=0;aa[i]!='\0';i++)
    {
        if(aa[i]<=a)
        continue;
        c++;
    }
    return c;
}
void construct_tree(int pre[])
{
    int in[20];
    getInorder(in,pre);
    int bfr,aft,pos,r,l,ar1[10],ar2[10];
    if(pre[0]!='\0')
    insert(pre[0]);
    pos=find(pre[0],in);
    bfr=before(pre[0],in);
    aft=after(pre[0],in);
    if(bfr!=0)
    {
    slice(pre,1,bfr,ar1);
    construct_tree(ar1);
    }
    if(aft!=0)
    {
    slice(pre,pos+1,pos+aft,ar2);
    construct_tree(ar2);
    }
}
int main()
{
    int i,d;
    printf("Enter the number of elements in tree\n");
    scanf("%d",&n);
    printf("Enter Preorder: ");
    for(i=0;i<n;i++)
    scanf("%d",&pre[i]);
    construct_tree(pre);
    printf("Inorder : ");
    inorder(root);
    printf("NULL\n");
    printf("Preorder : ");
    preorder(root);
    printf("NULL\n");
    printf("Postorder : ");
    postorder(root);
    printf("NULL\n");
}