#include<stdio.h>

#define MAX 5
int Q[MAX];
int front = -1, rear = -1;

void insert(int item)
{

    if(front  == (rear+1)%MAX)
    {
        printf("Overflow \n");
        return ;

    }

    rear =  (rear+1)%MAX;
    Q[rear] = item;
    if(front == -1)
    {
        front = 0;
    }
}

int delete()
{
    int item;
    if(front == -1)
    {
        printf("Underflow \n");
        return -1;

    }
    item = Q[front];

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
     front=(front+1)%MAX ;
    return item;
}

void display()
{
    int i;
    if(front == -1)
    {
        printf("Underflow \n");
        return ;

    }
    for(i=front ; i!= rear; i= (i+1)%MAX)
    {
        printf("%d \t", Q[i]);
    }
    printf("%d",Q[i]);
    printf("\n");
}

int main()


{

int i,n,choice;



while(1)
{

printf("The following operations can be performed on a circular queue:\n");

printf("1.Insert\n2.Delete\n3.Display\nAny other number to exit\n");

printf("Enter your choice\n");

 scanf("%d",&choice);

 switch(choice)

 {

case 1:


printf("Enter the number to be entered into the queue\n");

 scanf("%d",&n);
 insert(n);


break;

 case 2:

delete();
break;


 case 3:

 display();

break;

default:

exit(0);



}


}



 return 0;

}