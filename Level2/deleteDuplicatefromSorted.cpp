/*
2-Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

algo:
if the data is equal traverse 
otherwise store it and 
repeat the step
*/
/**
My algo:
c=0;
if(data!=next->data)
		push into the stack and if c!=0 pop;
else check if it is equal to stack top then c++;	

if(c!=0)
	s.pop();
if(s.empty()==true)
	return NULL;
**/
 
ListNode* reverse(ListNode* head)
{
    ListNode* prev,*curr,*next;
    prev=NULL;
    curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
ListNode* Solution::deleteDuplicates(ListNode* head)
{
    ListNode* temp=head;
    stack<ListNode*> s;
    s.push(temp);
    int c=0;
    while(temp->next!=NULL)//if(temp!=NULL) then segfault
    {
        temp=temp->next;
        if(temp->val!=s.top()->val)
        {
            if(c!=0)
                s.pop();
            s.push(temp);
            c=0;
        }
        else c++;
    }
    if(c!=0)
        s.pop();
    if(s.empty()==true)
        return NULL;
    ListNode* h=NULL;
    ListNode* y=NULL;
    h=s.top();
    s.pop();
    y=h;
    while(!s.empty())
    {
        h->next=s.top();
        h=h->next;
        s.pop();
    }
    h->next=NULL;
    y=reverse(y);
    return y;
    
}


/*
node* remdu(node *head1)
{
	node *temp,*r,*curr;
	temp=curr=head1;
	r=NULL;
	
	while(curr!=NULL)
	{
		int data=curr->data;
		int c=0;
		while(curr!=NULL && curr->data==data)
		{
			curr=curr->next;
			c++;
		}
		if(c==1)
		{
			temp->data=data;//i.e head1->data
			r=temp;
			temp=temp->next;
		}
	}
	if(r!=NULL)
		r->next=NULL;
	else
		head1=NULL;
	return head1;	
}*/