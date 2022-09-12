/* C program to implement the list of faculty with the fields Name,age and department.
Insert node at the rear end of list
Display the faculty details for the given dept whose age is less than 35
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[10];
    int age;
    char dept[10];
    struct node *next;
};
struct node *head = NULL;
void insertbegin()
{
    int i;
    struct node *newnode, *temp = head;
    if (head == NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the name\n");
        scanf("%s", &newnode->name);
        printf("Enter the age\n");
        scanf("%d", &newnode->age);
        printf("Enter the Department \n");
        scanf("%s", &newnode->dept);
        newnode->next = NULL;
        head = newnode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the name");
    scanf("%s", &newnode->name);
    printf("Enter age\n");
    scanf("%d", &newnode->age);
    printf("Enter the department");
    scanf("%s", &newnode->dept);
    temp->next = newnode;
    newnode->next = NULL;
}
void traverse(struct node *temp)
{
    printf(" The Details are\n");
    printf("The Name is ");
    puts(temp->name);

    printf("\n");
    printf("The Age is: %d \n ", temp->age);
    printf("The Department is\n:");
    puts(temp->dept);
    printf("\n");
}

void display()
{
    struct node *temp = head;
    char department[10];
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    // printf("Enter the department \n");
    gets(department);

    while (temp != NULL && strcmp(department, temp->dept))
    {
        if (temp->age < 35)
        {
            traverse(temp);
        }
        temp = temp->next;
    }
}
void main()
{
    int ch;
    while (1)
    {

        printf("Enter 1 to add a node in the front and 2 to display faculty details for thoes whose age is less than 35 \n");
        printf(" \n enter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertbegin();
            break;

        case 2:
            display();
            break;

        default:
            exit(1);
        }
    }
}