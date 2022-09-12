#include<stdio.h>
#include<string.h>
#define MAX 5
struct patient
{
    int id;
    char name[10];

};
struct patient Q[MAX];
int front = -1, rear = -1;

void insert()
{
    struct patient newp;
    
    if(front  == (rear+1)%MAX)
    {
        printf("Overflow \n");
        return ;

    }

    rear =  (rear+1)%MAX;
    scanf("%d",&newp.id);
    printf("enter patient name");
    scanf("%s",&newp.name);
    Q[rear] = newp;
    if(front == -1)
    {
        front = 0;
    }
}

struct patient delete()
{
    struct patient thing;

    if(front == -1)
    {
        printf("Underflow \n");
        return;

    }
    thing = Q[front];

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
     front=(front+1)%MAX ;
    return thing;
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
        printf("age: %d\n",Q[i].id);
        printf("name: ");
        puts(Q[i].name);

    }
     printf("age: %d",Q[i].id);
     printf("name: ");
     puts(Q[i].name);
}

int main()

{

int i,n,choice;
struct patient p;


while(1)
{

printf("The following operations can be performed on a circular queue:\n");

printf("1.Insert\n2.Delete\n3.Display\nAnyother number to exit\n");

printf("Enter your choice\n");

 scanf("%d",&choice);

 switch(choice)

 {

case 1:


printf("Enter the patient details: age and name \n");
 insert();


break;

 case 2:

        p=delete();
        printf("age: %d\n",p.id);
        printf("name: ");
        puts(p.name);

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
