
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printAlternateNode(struct Node *head)
{
    int count = 0;

    while (head != NULL)
    {

        if (count % 2 == 0)
            printf(" %d ", head->data);

        count++;

        head = head->next;
    }
}

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    struct Node *head = NULL;

    push(&head, 12);
    push(&head, 29);
    push(&head, 11);
    push(&head, 23);
    push(&head, 8);

    printAlternateNode(head);

    return 0;
}










void alternate()
{
    struct node * temp=head;
    if(head==NULL)
    {
        printf("Empty list");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next->next;
    }
}