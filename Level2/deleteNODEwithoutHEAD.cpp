/*
Delete without head pointer

You are given a pointer/reference to a node to be deleted in a linked list. The task is to delete the node.
  Pointer/reference to head node is not given. 

You may assume that the node to be deleted is not the last node.

A simple solution is to traverse the linked list until you find the node you want to delete. 
But this solution requires pointer to the head node which contradicts the problem statement.

Fast solution is to copy the data from the next node to the node to be deleted and delete the next node.
 Something like following.

 
	if(node_ptr->next==NULL) return;
    node *temp  = node_ptr->next;
  
	node_ptr->data  = temp->data;
    node_ptr->next  = temp->next;
    delete temp;
*/

