#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int towers(int n,char s,char d, char t)
{
    if(n==1)
    {
        printf("Move 1 from %c to %c \n",s,d);
    }
    else
    {
        towers(n-1,s,t,d);
        printf("Move %d from %c to %c \n",n,s,d);
        towers(n-1,t,d,s);
    } 
}
   
   
void main()
{
int n;
printf("Enter the number of disks");
scanf("%d",&n);
towers(n,'s','d','t');
}
