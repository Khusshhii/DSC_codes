// C program to construct an AVL tree 
#include<stdio.h> 
#include<stdlib.h> 

// An AVL tree node 
struct Node 
{ 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int BalFactor; 
}; 


// A utility function to get the height of the tree 
int height(struct Node *N) 
{ 
	int lDepth, rDepth;
	if (N == NULL) 
		return -1; 
	else 
   { 
       /* compute the depth of each subtree */
       lDepth = height(N->left); 
       rDepth = height(N->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
	
} 

 
/* Helper function that allocates a new node with the given key and 
	NULL left and right pointers. */
struct Node* newNode(int key) 
{ 
	struct Node* node = (struct Node*) 
						malloc(sizeof(struct Node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->BalFactor = 0; // new node is initially added at leaf 
	return(node); 
} 

// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
struct Node *rightRotate(struct Node *x) 
{ 
	struct Node *y = x->left; 
	struct Node *y_rst= y->right; 

	// Perform rotation 
	y->right = x; 
	x->left = y_rst; 

	// Update heights 
	x->BalFactor = height(x->left)- height(x->right); 
	y->BalFactor = height(y->left)- height(y->right); 

	// Return new root 
	return y; 
} 

// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
struct Node *leftRotate(struct Node *x) 
{ 
	struct Node *y = x->right; 
	struct Node *y_lst = y->left; 

	// Perform rotation 4
	y->left = x; 
	x->right = y_lst; 

	// Update heights 
	y->BalFactor = height(y->left)-height(y->right); 
	x->BalFactor = height(x->left)-height(x->right); 

	// Return new root 
	return y; 
} 

int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
struct Node* insert(struct Node* root, int key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (root == NULL) 
		return(newNode(key)); 

	if (key < root->key) 
		root->left = insert(root->left, key); 
	else if (key > root->key) 
		root->right = insert(root->right, key); 
	else // Equal keys are not allowed in BST 
		return root; 

	/* 2. Update height of this ancestor node */
	//root->BalFactor = height(root->left)-height(root->right);

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	root->BalFactor = getBalance(root); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 
    int balance= root->BalFactor;
	// Left Left Case 
	if (balance > 1 && key < root->left->key) 
		{
			printf("Imbalance node = %d, Balfactor= %d\n",root->key,root->BalFactor);
			printf("Rotataion on nodes %d, %d, %d\n",root->key,root->left->key,root->left->left->key);
			return rightRotate(root); 
		}
	// Right Right Case 
	if (balance < -1 && key > root->right->key) 
	{
			printf("Imbalance node = %d, Balfactor= %d\n",root->key,root->BalFactor);
			printf("Rotation on nodes %d, %d, %d\n",root->key,root->right->key,root->right->right->key);
				return leftRotate(root);
	}
	 

	// Left Right Case 
	if (balance > 1 && key > root->left->key) 
	{ 
		printf("Imbalance node = %d, Balfactor= %d\n",root->key,root->BalFactor);
		printf("Rotataion on nodes %d, %d, %d\n",root->key,root->left->key,root->left->right->key);
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 

	// Right Left Case 
	if (balance < -1 && key < root->right->key) 
	{ 
		printf("Imbalance node = %d, Balfactor= %d\n",root->key,root->BalFactor);
		printf("Rotataion on nodes %d, %d, %d\n",root->key,root->right->key,root->right->left->key);
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 

	/* return the (unchanged) node pointer */
	return root; 
} 
struct Node *inorder_successor(struct Node *root)
   {
   	 struct Node *p = root;
   	while(p->left != NULL)
      {
        p = p->left;
      }   
     return p;    
   }

  
struct Node* deleteNode(struct Node* root, int key) 
{ 
    if (root == NULL) 
        return root; 
  
    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is 
    // the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            struct Node *temp = root->left ? root->left : 
                                             root->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
             *root = *temp; // Copy the contents of 
                            // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            struct Node* temp = inorder_successor(root->right); 
  
            // Copy the inorder successor's data to this node 
            root->key = temp->key; 
  
            // Delete the inorder successor 
            root->right = deleteNode(root->right, temp->key); 
        } 
    } 
  
    // If the tree had only one node then return 
    if (root == NULL) 
      return root;  
  
    // GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
    int balance = getBalance(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // L1 or L0 Case -Perform LL Rotation 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
  
    // L-1 Case - Perform LR Rotation
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    } 
  
    // R-1 or R0 Case -Perfrom RR Rotation 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 
  
    // R1 Case - Perform RL Rotation
    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
} 


void inOrder(struct Node *root) 
{ 
	if(root != NULL) 
	{ 
		inOrder(root->left); 
		printf("%d ", root->key); 
		inOrder(root->right); 
	} 
} 


int main() 
{ 
struct Node *root = NULL;
int num;
root = insert(root, 30); 
root = insert(root, 20); 
root = insert(root, 10); 
root = insert(root, 40); 
root = insert(root, 50); 
root = insert(root, 25); 
printf("Inorder traversal of the constructed AVL tree\n"); 
inOrder(root); 
printf("Enter the element to delete\n");
scanf("%d", &num);
deleteNode(root, num);
printf("Inorder traversal of the AVL tree after Deletion tree is \n"); 
inOrder(root); 
return 0; 

} 
