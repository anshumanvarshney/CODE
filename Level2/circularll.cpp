#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node *next;
};
 
Node *addToEmpty(Node *last, int data)
{
   
    if (last != NULL) //it is not empty
      return last;
	  
    Node *temp = new Node;
    temp -> data = data;
    last = temp;
 
    last -> next = last;//self
    return last;
}

Node *addBegin(Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
 
    Node *temp = new Node;
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
 
    return last;
}
 
Node *addEnd(Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
     
     Node *temp = new Node;
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
 
    return last;
}
 
Node *addAfter(Node *last, int data, int item)
{
    if (last == NULL)
        return NULL;
 
    Node *temp, *p;
    p = last -> next;//means head;
    do
    {
        if (p ->data == item)
        {
            temp = new Node;
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;
 
            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    }  while(p != last -> next);
 
    cout << item << " not present in the list." << endl;
    return last;
 
}
 /*
void traverse(Node *last)
{
     Node *p;
 
    // If list is empty, return.
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
 
    // Pointing to first Node of the list.
    p = last -> next;
 
    // Traversing the list.
    do
    {
        cout << p -> data << " ";
        p = p -> next;
 
    }
    while(p != last->next);
 
}*/

int main()
{
    Node *last = NULL;
    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);
    traverse(last);
    return 0;
}
/*
Output:

2 4 6 8 10 12 
*/


//insert at beg
void push(struct node **head_ref, int data)
{
    node *ptr1 = new node;
    node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;
 
    /* If linked list is not NULL then set the next of last node */
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */
 
    *head_ref = ptr1;
}
 /*
void printList(node *head)
{
    node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}*/
//

//or 
void printList(struct node *head)
{
    node *temp = head;
    node *p=NULL;
	while(temp!=p)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
		p=head;
	}
}

int main()
{
    node *head = NULL;
 
    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
 
    printf("Contents of Circular Linked List\n ");
    printList(head);
    return 0;
}
/*
Contents of Circular Linked List
 11 2 56 12
 */
 
 
//sorted insert in circular linked list
void sortedInsert(Node** head, int data)
{
    Node *temp,*old,*r,*curr;
    if(*head==NULL)//if ll is empty
    {
        (*head)=new Node;
        (*head)->data=data;
        (*head)->next=(*head);
    }
    else if((*head)->data>=data)//if first ele is greater
    {
        temp=new Node;
        temp->data=data;
        curr=*head;
        while(curr->next!=*head)
            curr=curr->next;
        curr->next=temp;
        temp->next=*head;
        *head=temp;
    }
    else//otherwise
    {
        temp=*head;
        r=new Node;
        r->data=data;
        while ( temp->next!= *head&& temp->next->data < r->data)
        {
            temp = temp->next;
        }
        r->next = temp->next;
        temp->next = r; 
    }
}		 
		 
		 
		 
		 
		 
		 

//split a circular linked list into two halves
/*
Input:
2
3
1 5 7
4
2 6 1 5

Output:
1 5
7
2 6
1 5
*/
void splitList(Node *head, Node **head1, Node **head2)
{
  Node *slow = head;
  Node *fast = head; 
 
  if(head == NULL)
    return;
  
  while(fast->next != head && fast->next->next != head) 
  {
     fast = fast->next->next;
     slow = slow->next;
  }  
  
  if(fast->next->next == head)
     fast = fast->next;      
  //assign head
  *head1 = head;    
  *head2 = slow->next;
  //make circular ll
  fast->next = slow->next;
  slow->next = head;       
}