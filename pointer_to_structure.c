#include <stdio.h>
struct employees
{
    char name[20];
    int age;
    float salary;
};
int main()
{
struct employees e1;
struct employees *e1ptr;
e1ptr=&e1;
printf("details of employees:\n");
printf("Enter the name:");
scanf("%s",&e1ptr->name);
printf("Enter the age:");
scanf("%d",&e1ptr->age);
printf("Enter the salary :");
scanf("%f",&e1ptr->salary);
printf("details of employees:\n");
printf("Name: %s \n Age: %d \nSalary: %f",e1ptr->name,e1ptr->age,e1ptr->salary);
return 0;
}