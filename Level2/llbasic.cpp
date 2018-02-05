//double
//Add after a node
void linklist ::addf(int num)
{
	node *temp,*old,*r;
	int n;
	cout<<"\nEnter the node_after :  ";
	cin>>n;
		temp=p;
		while(temp->data!=n)
		{
			old=temp;
			temp=temp->next;
		}
		r=new node;
		r->prev=temp;
		r->data=num;
		r->next=temp->next;
		r->next->prev=r;
		temp->next=r;
}
//delete before a node
void linklist ::delb()
{
	node *temp,*old;
	int n;
	cout<<"\nEnter the node_after :  ";
	cin>>n;
		temp=p;
		while(temp->data!=n)
		{
			old=temp;
			temp=temp->next;
		}
		old->next->prev=old->prev;//temp->prev=old prev
		old->prev->next=old->next;
		delete old;
}

//Delete after a node
void linklist ::delf()
{
	node *temp,*old;
	int n;
	cout<<"\nEnter the node_after :  ";
	cin>>n;
		temp=p;
		while(temp->data!=n)
		{
			old=temp;
			temp=temp->next;
		}
		
		/*
		or 
		old = temp->next->next;
	    temp->next=old->next;
		
		*/
		temp=temp->next; //because its after a node
		temp->next->prev=temp->prev;
		temp->prev->next=temp->next;
		delete temp;
}
//deletion in doubly
void linklist::del(int num)
{
 node *temp,*old;
 temp=p;
 while(temp!=NULL)
 {
	if(temp->data==num)
	{
		if(temp==p)  //if node is to be deleted is first node
		{
			p=temp->next;
			p->prev=NULL;  //note
		}
		else
		{
			if(temp->next==NULL)//last node
			{
				old->next=NULL;
			}
			else
			{
				old->next=temp->next;
				temp->next->prev=old;//it must be there
			}
		}
		delete temp;
		return;
	}
	old=temp;
   temp=temp->next;
 }
 cout<<"\n\nElement "<<num<<"not found";
}

//reverse doubly
Node* Reverse(Node* head)
{
    Node *current,*prev,*next;
    if(head==NULL)return NULL;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        current->prev=next;
        prev=current;
        current=next;
    }
    return prev;
}

Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    Node *temp;
    temp=NULL;
    if (headA == NULL) {
        return headB;
    }
	if (headB== NULL) {
        return headA;
    }

    if (headA->data <= headB->data) {
        temp=headA;
        temp->next = MergeLists(headA->next, headB);
        
    } 
	if (headA->data > headB->data){
        temp=headB;
        temp->next = MergeLists(headA, headB->next);
        
    }
    return temp;
    
} 
//strcmp()
int list :: stcmp(node *a,node *b)
{
	while(a!=NULL && b!=NULL && a->data == b->data)
	{
		a=a->link;
		b=b->link;
	}
	if (a!=NULL && b!=NULL) //if not equal
        return (a->data > b->data)? 1:-1;
    if (a!=NULL && b==NULL) return 1;
    if (b!=NULL && a==NULL) return -1;
     
    return 0;//if both are equal
}

/*note if we pass single pointer in both the node then 
if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become
   1->4->2->5->3->6 and second list to 4->2-5->3->6.*/
void list :: alter(node *headA,node **headB)
{
	 node *p1 = headA;
	 node *q1 = *headB;//note
     node *p2, *q2;
 
     while (p1 != NULL && q1 != NULL)
     {
         p2 = p1->link;
         q2 = q1->link;
		 p1->link = q1; 
         q1->link = p2;  
         p1 = p2;
         q1 = q2;
    }
	*headB = q1; // Update head pointer of second list (it may be possinle if second list is greater than first list)
	//For example,if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become
   //1->4->2->5->3->6 and second list to 7->8.
}