#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int towers(int n,char a,char b, char c)
{
    if(n==1)
    {
        printf("Move 1 from %c to %c \n",a,b);
    }
    else
    {
        towers(n-1,a,c,b);
        printf("Move %d from %c to %c \n",n,a,b);
        towers(n-1,c,b,a);
    }
}

void main()
{
int n;
printf("Enter the number of disks");
scanf("%d",&n);
towers(n,'a','b','c');
}