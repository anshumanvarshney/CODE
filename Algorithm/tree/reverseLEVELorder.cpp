/*
Reverse Level Order Traversal
Write a function to print Reverse Level Order Traversal of a tree. For below tree, function should print 4 5 2  3 1
		
	 1
       /   \
      2     3
   /   \
  4	5
  */
  
  //using stack and queue
  void reversePrint(Node *root)
  {
	  queue<Node *> q1;
	  stack<Node *> s2;
	  q1.push(root);
	  while(!q1.empty())
	  {
		  Node *temp=q1.front();
		  s2.push(temp);
		  q1.pop();
		  if(temp->right!=NULL)
			  q1.push(temp->right);
		  if(temp->left!=NULL)
			  q1.push(temp->left);
	  }
	  while(!s2.empty())
	  {
		  cout<<s2.top()->data<<" ";
		  s2.pop();
	  }
  }
