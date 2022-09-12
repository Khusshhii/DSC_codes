#include<stdio.h>
void search(int a[],int n)
{
    
    int pos=-1,i,ele;
    printf("enter search element");
    scanf("%d",&ele);
    for(i=0;i<n;i++)
    {
        if(a[i]==ele)
        {
            pos=i;
            break;
        }
    }
    int res=pos;
     if(res<0)
    {
        printf("element does not exist");
    }
    else
    {
        printf("element found at %d",res);
    }
  
}
int main()
{
    int n,a[20],res;
    printf("Enter array limit");
    scanf("%d",&n);
    printf("enter the array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    search(a,n);
   
    return 0;
}
