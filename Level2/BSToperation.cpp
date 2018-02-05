/*
Binary Search Tree, is a node-based binary tree data structure which has the following properties:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree.
There must be no duplicate nodes.

The above properties of Binary Search Tree provide an ordering among keys so that the operations like search, 
minimum and maximum can be done fast. If there is no ordering, then we may have to compare every key to search a given key.

Searching a key
To search a given key in Bianry Search Tree, we first compare it with root, if the key is present at root, 
we return root. If key is greater than root’s key, we recur for right subtree of root node. Otherwise 
we recur for left subtree.

Insertion of a key
A new key is always inserted at leaf. We start searching a key from root till we hit a leaf node.
 Once a leaf node is found, the new node is added as a child of the leaf node.

         100                               100
        /   \        Insert 40            /    \
      20     500    --------->          20     500 
     /  \                              /  \  
    10   30                           10   30
                                              \   
                                              40

*/

//insertion in BST
node *insert(node *sr,int num)
{
	
	if(sr==NULL)    
	{
		sr=new node;
		sr->left=NULL;
		sr->data=num;
		sr->right=NULL;
		return sr;
	}
			//in place of this you can also use newnode function 
			i.e
			if(sr==NULL)    
			{
				return newnode(sr);
			}
	else
	{
		if(num<sr->data)
			sr->left =insert(sr->left,num);
		else
		{ 
	        sr->right =insert(sr->right,num);
        }
	}
	return sr;
}

//searching in BST
// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;//if root==null return null(root)
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}



//minimum/maximum  value in BST(logic)
/*
This is quite simple. Just traverse the node
 from root to left recursively until left is NULL. The node whose left is NULL is the node with minimum value.
*/

int minValue(struct node* node) {
  struct node* current = node;
 
  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return(current->data);
}

//height of binary tree
//do it by drawing tree
int btree :: height (node *sr)
{
	int l,r;
	if(sr==NULL)
	{
		return 0;
	}
	else 
	{
		l= height(sr->left);
		r= height(sr->right);
		return 1+(l > r)?l:r;//return to its calling function
	}
}

//total node 
int btree :: tn(node *sr)
{
	if(sr==NULL)
		return 0;
	else return (tn(sr->left)+tn(sr->right)+1);
}


//form mirror image
//for this take eg : 5 3 4 8
node* btree :: mi(node *sr)
{
	node *ptr;
	if(sr!=NULL)
	{
		mi(sr->left);//for every node left child become right child and vice versa
		mi(sr->right);
		ptr=sr->left;
		sr->left=sr->right;
		sr->right=ptr;
	}
}

//total internal node
int btree :: tin(node *sr)
{
	if(sr==NULL || (sr->left == NULL && sr->right == NULL))
		return 0;
	else return (tin(sr->left)+tin(sr->right)+1);//1 for root node
}

//total external node
int btree :: ten(node *sr)
{
	if(sr==NULL ) 
		return 0;
	else 
		if(sr->left == NULL && sr->right == NULL)
			return 1; 
	else return (ten(sr->left)+ten(sr->right));
}

/*
Time Complexity: The worst case time complexity of search and insert operations is O(h) where h is height 
of Binary Search Tree. In worst case, we may have to travel from root to the deepest leaf node. 
The height of a skewed tree may become n and the time complexity of search and insert operation may become O(n).
*/

//deletion in BST

/*
 When we delete a node, there possibilities arise.

1) Node to be deleted is leaf: Simply remove from the tree.

              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70 
         /  \    /  \                     \    /  \ 
       20   40  60   80                   40  60   80

2) Node to be deleted has only one child: Copy the child to the node and delete the child

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70 
            \    /  \                          /  \ 
            40  60   80                       60   80

3) Node to be deleted has two children: Find inorder successor of the node. 
Copy contents of the inorder successor to the node and delete the inorder successor. 
Note that inorder predecessor can also be used.

              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70 
                 /  \                            \ 
                60   80                           80
				
The important thing to note is, inorder successor is needed only when right child is not empty. 
In this particular case, inorder successor can be obtained by finding the minimum value in right child of the node.
*/


/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;//it return to recursive call i.e root->left
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;//return when 50 is deleted//after all the operation we have to return the root
}
 
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    return 0;
}
/*
Inorder traversal of the given tree
20 30 40 50 60 70 80
Delete 20
Inorder traversal of the modified tree
30 40 50 60 70 80
Delete 30
Inorder traversal of the modified tree
40 50 60 70 80
Delete 50
Inorder traversal of the modified tree
40 60 70 80
*/
/*
Time Complexity: The worst case time complexity of delete operation is O(h) where h is height of Binary Search Tree.
 In worst case, we may have to travel from root to the deepest leaf node. 
The height of a skewed tree may become n and the time complexity of delete operation may become O(n)
*/


//Inorder Successor/pressessor(logic) in Binary Search Tree
/*
In Binary Tree, Inorder successor of a node is the next node in Inorder traversal of the Binary Tree.
 Inorder Successor is NULL for the last node in Inoorder traversal.
In Binary Search Tree, Inorder Successor of an input node can also be defined as the node with the smallest key 
greater than the key of input node. So, it is sometimes important to find next node in sorted order.
 */
 
 //my method solution for practice geeksforgeeks
 void inorder(Node *root,int a[],int &c)
{
    if(root!=NULL)
    {
        inorder(root->left,a,c);
        a[c++]=root->data;
        inorder(root->right,a,c);
    }
}

Node * inOrderSuccessor(Node *root, Node *x)
{
    int a[1000],c=0,i,t=-1;
    inorder(root,a,c);
    for(i=0;i<c;i++)
    {
        if(a[i]>x->data)
        {
            t= a[i];
            break;
        }
    }
    Node *temp=new Node;
    temp->data=t;
    temp->left=temp->right=NULL;
    return temp;
}