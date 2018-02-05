/*
Remove every k'th node
Given a singly linked list, Your task is to remove every Kth node. The task is to complete a method deleteK
that takes two argument, head of linked list and an integer k. The method returns the head of the new linked list.
There are multiple test cases.
For each test case, this method will be called individually
 
 
Input:
2
8
1 2 3 4 5 6 7 8
3
4
1 2 3 4
2

Output:
1 2 4 5 7 8
1 3
*/

node *everyk(node *head,int k)
{
	if(head==NULL)
		return NULL;
	node *temp,*old,*r;
	temp=head;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		if(c==k)
		{
			r=temp;
			temp=temp->next;
			old->next=temp;
			delete r;
			c=0;
		}
		if(c!=0)
		{
			old=temp;
			temp=temp->next;
		}
	}
	
	return head;
}