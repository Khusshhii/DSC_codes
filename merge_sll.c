Node* MergeLists(Node *list1, Node *list2) 
{
if (list1) return list2;

if (list2) return list1;

Node *head;
//Chosing head of merged list
if (list1->data< list2->data) 
{
head=list1;
} 
else 
{ 
head=list2;
list2=list1;
list1=head;
}
while(list1->next && list2) {
if (list1->next->data > list2->data) {
//Step 1. Save the next pointer
Node *tmp = list1->next;
//Step 2. Change next pointer to point L
list1->next = list2;
//Step 3. Move L2 to temp
list2 = tmp;
}
//Step 4. Move L1 ahead 
list1= list1->next;
} 

if (list1->next) 
list1->next = list2; 
return head;
}