#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int z=-89;
int max1(int A[],int n)
{
    if(n==1)
    return (A[0]);
    //return comp(A[n-1], max1(A,n-1));
    if(A[0]>z)
    {
        z=A[0];
    }
    max1(A+1,n);
    return z;

}
/*
int comp(int x,int y)
{
    if(x>y)
    return x;
    return y;
}
*/

void main()
{
int p,n,i,A[10];
printf("Enter the number of elements in the array");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&A[i]);
}
p=max1(A,n);
printf("HIghest %d",p);
}






/*

#include<stdio.h>
int mini(int x,int y)
{
    if(x>y)return y;
    return x;
}
int min(int a[],int n)
{
    if(n==1)
    return a[0];
    else
    return mini(a[n-1],min(a,n-1));
}
int maxx(int x,int y)
{
    if(x<y)return y;
    return x;
}
int max(int a[],int n)
{
    if(n==1)
    return a[0];
    else
    return maxx(a[n-1],max(a,n-1));
}
int main()
{
    int n,a[100];
    printf("Enter the no of elements in the array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int minres=min(a,n);
    printf("%d \n",minres);
    int maxres=max(a,n);
    printf("%d",maxres);
}

*/