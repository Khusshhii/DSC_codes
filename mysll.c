#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head = NULL;
void traverse()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Empty list");
        return;
    }
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
}
void insert_Begin(int x)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = x;
    new_node->next = head;
    head = new_node;
}
void insert_end(int y)
{
    struct node *new_node;
    struct node *temp = head;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = y;
    new_node->next = NULL;
    if (temp == NULL)
    {
        head = new_node;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void minval()
{
    struct node *temp = head;
    int min = temp->info;
    if (head == NULL)
    {
        printf("Empty list \n");
        return;
    }

    while (temp != NULL)
    {
        if (temp->info <= min)
        {
            min = temp->info;
            // temp = temp->next;
        }
        temp = temp->next;
    }
    printf("%d is the min value \n", min);
}

void countnodes()
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("NO. of nodes are %d \n", count);
}

void lastnode()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Empty list");
        return;
    }
    while (temp->next != NULL)
    {

        temp = temp->next;
    }

    printf("last node is %d", temp->info);
}

void deletebegin()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("Nothing to delete");
    }
    head = head->next;
    free(temp);
}

void deleteend()
{

    struct node *temp = head;
    struct node *cur = head;
    if (temp == NULL)
    {
        printf("Nothing to delete");
    }
    while (temp->next != NULL)
    {
        cur = temp;
        temp = temp->next;
    }
    free(temp);
    cur->next = NULL;
}

void deleteany(int item)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Nothing to delete");
    }

    if (head->info == item)
    {

        head = head->next;
        free(temp);
    }
    struct node *cur = head;
    while (cur->info != item)
    {
        temp = cur;
        cur = cur->next;
        if (cur == NULL)
            break;
    }
    if (cur == NULL)
    {
        printf("Not found");
        return;
    }

    else
    {
        temp->next = cur->next;
        free(cur);
        printf("Value Deleted");
    }
}
void insertatpos(int pos, int val)
{
    int count = 0;
    struct node *temp = head;
    struct node *cur = head;
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->info = val;
    while (temp != NULL)
    {
        count++;
        cur=temp;
        temp = temp->next;
        if(count==pos)
        break;
    }
    
    
    new_node->next = temp;
    cur->next= new_node;

}

int main()
{
    int c;
    struct node *head = NULL;
    // traverse();
    // printf("\n");
    int ch;
    while (1)
    {
        printf("\n 1 for traverse \n 2 for insert_begin \n 3 for insert_end \n  4 for minval \n 5 for counting nodes \n 6 for lastnode \n 7 for delete begin \n 8 for delete end \n 9 to delete any value \n 10 to insert at any pos \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            traverse();
            break;
        case 2:
            int x;
            printf("Enter x \n");
            scanf("%d", &x);

            insert_Begin(x);
            break;
        case 3:
            int y;
            printf("Enter y \n");
            scanf("%d", &y);

            insert_end(y);
            break;
        case 4:
            minval();
            break;
        case 5:
            countnodes();
            break;
        case 6:
            lastnode();
            break;
        case 7:
            deletebegin();
            break;
        case 8:
            deleteend();
            break;
        case 9:
            int item;
            printf("Enter value to be deleted");
            scanf("%d", &item);
            deleteany(item);
            break;
        case 10:
            int pos,val;
            printf("Enter position of insertion");
            scanf("%d",&pos);
            printf("Enter value to be inserted");
            scanf("%d", &val);
            insertatpos(pos,val);
            break;
        }
    }

    // insert_Begin(x);
    // insert_Begin(x);
    // insert_Begin(x);
    // traverse();
    // minval();

    // return 0;
}