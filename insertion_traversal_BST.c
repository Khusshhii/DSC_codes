
#include<stdio.h>
#include<stdlib.h>
struct BST
{
	struct BST *left;
	int info;
	struct BST *right;
};
struct BST *root=NULL;
int countl=0;
void insert(int n)
{
	struct BST *newnode,*temp=root,*prev;
	newnode=(struct BST *)malloc(sizeof(struct BST));
	newnode->info=n;
	newnode->right=NULL;
	newnode->left=NULL;
	if(root==NULL)
	{
		
		root=newnode;
		return;
	}
	while(temp!=NULL)
	{
		prev=temp;
		if(temp->info>n)
		{
			temp=temp->left;
			prev->left=newnode;
		}
		else
		{
			temp=temp->right;
			prev->right=newnode;
		}
	}
	
}
void inorder(struct BST *r)
{
	if(r!=NULL)
	{
	
	inorder(r->left);
	printf("%d	",r->info);
	inorder(r->right);
	}
}
void preorder(struct BST *r)
{
	if(r!=NULL)
	{
	
	printf("%d	",r->info);
	preorder(r->left);
	preorder(r->right);
	}

}
void postorder(struct BST *r)
{
	if(r!=NULL)
	{
	postorder(r->left);
	postorder(r->right);
	printf("%d	",r->info);
	}
}
int countc(struct BST *r)
{
	if(r==NULL)
	return 0;
	else if(r->left==NULL && r->right==NULL)
	return 1;
	else
	return (count(r->left)+count(r->right));
	
}
int countp()
{
	struct BST *temp=root;
	if(root==NULL)
	return 0;
	while(temp->left!=NULL && temp->right!=NULL)
	{
		count
	}
	
}
void min()
{
	struct BST *temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	printf("%d",temp->info);
}
void max()
{
	struct BST *temp=root;
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	printf("%d",temp->info);
}
int maxnum(int x,int y)
{
	if(x>y)
	return x;
	return y;
}
int height(struct BST *r)
{
	
	if(r==NULL)
	return -1;
	return maxnum(height(r->left),height(r->right))+1;

	
}
void main()
{
	int choice,n,res;
	for(;;)
	{
	    scanf("%d",&choice);
		switch(choice)
		{
		case 1:
		printf("enter the number\n");
		scanf("%d",&n);
		insert(n);
		break;
		case 2:
		inorder(root);
		break;
		case 3:
		preorder(root);
		break;
		case 4:
		postorder(root);
		break;
		case 5:
		countl=count(root);
		printf("%d\n",countl);
		break;
		case 6:
		max();
		break;
		case 7:
		res=height(root);
		printf("%d",res);
		break;
		default:
		exit(0);
		}
	}
}
