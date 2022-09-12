#include <stdio.h>
int top = -1, a[100],size;
void display()
{
    printf("\n 1) Push");
    printf("\n 2) Peek");
    printf("\n 3) Pop");
    printf("\n 4) Display");
    printf("\n -1) To Exit");
    printf("\n Enter Your choice : ");
}
void push(int x)
{
    if (top == (size - 1))
    {
        printf("Overflow \n");
        return;
    }
    top = top + 1;
    a[top] = x;
}
void peek()
{
    if (top == -1)
    {
        printf("Empty list ");
        return;
    }
    printf("\n The top most element is %d", a[top]);
}
void pop()
{
    int temp;
    if (top == -1)
    {
        printf("\n Cannot pop, Underflow");
        return;
    }
    temp = top;
    printf("\n %d is popped out", a[temp]);
    top = top - 1;
}

int main()
{
    int i, n, choice,number,flag=0;
    display();
    scanf("%d", &choice);
    while (choice != -1)
    {
        switch (choice)
        {
        case 1:
            if(flag==0)
            {
                 printf("\n Enter  size of Stack: ");
                 scanf("%d", &size);
                flag=1;
            }
            
            printf("\n Enter the Number to Push : ");   
            scanf("%d",&number);
            push(number);
            break;
        case 2:
            peek();
            break;
        case 3:
            pop();
            break;
        case 4:
            if(top==-1)
            printf("Empty stack");
            printf("\n The Elements are : ");
            for(int i = 0; i <=top; i++)
            {
                printf("%d ", a[i]);
            }
            break;
        default:
             printf("\n Wrong Choice , Try again ");
        }
        display();
        printf("\n\n Enter Your Choice : ");
        scanf("%d", &choice);
        
        if(choice ==-1){
            break;
        }

    }
    return 0;
}