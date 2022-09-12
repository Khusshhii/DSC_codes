struct node *Odd=NULL;
void EvenOddList(*head)
{
    struct node *cur=head,*prev,*t;
    while(cur!=NULL)
    {
    prev=cur;
    if(cur->info%2)
    {
        cur=cur->next;
    }
    else
    {
    insert(cur->info);
    prev->next=cur->next;
    t=cur->next;
    free(cur);
    cur=t;    
    }
    }
}
void insert(int x)
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=Odd;
    Odd=new_node;
}