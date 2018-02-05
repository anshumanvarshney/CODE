/*
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
we have to make merge point as we had made the cycle in mian function

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

eg:

1==      10->15->10->NULL

2== 	 3->6->9->15  note list 2 should not terminated at NULL
 
Note:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/


bool findIntersection(LinkedListNode* head1, LinkedListNode* head2) 
{
    int n=count(head1);
    int m=count(head2);
    int d;
    if(n>m)
    {
        d=n-m;
        while(d--)
            head1=head1->next;
    }
    else
    {
        d=m-n;
        while(d--)
            head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL)//  || can also be used inplace of &&
    {
        if(head1==head2)//because data can be same so compare node
            return true;
        head1=head1->next;
        head2=head2->next;
    }
    return false;
    

}


#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
  int data;
  node* next;
};

int getCount(node* head);
 
int _getIntesectionNode(int d, node* head1, node* head2);
//Method 1
int getIntesectionNode(node* head1, node* head2)
{
  int c1 = getCount(head1);
  int c2 = getCount(head2);
  int d;
 
  if(c1 > c2)
  {
    d = c1 - c2;
    return _getIntesectionNode(d, head1, head2);
  }
  else
  {
    d = c2 - c1;
    return _getIntesectionNode(d, head2, head1);
  }
}

int _getIntesectionNode(int d,node* head1,node* head2)
{
  int i;
  struct node* current1 = head1;
  struct node* current2 = head2;
 
  for(i = 0; i < d; i++)
  {
    if(current1 == NULL)
    {  
		return -1;
	}
    current1 = current1->next;
  }
 
  while(current1 !=  NULL && current2 != NULL)
  {
    if(current1 == current2)//compare only ll not data because data can be same
      return current1->data;
    current1= current1->next;
    current2= current2->next;
  }
 
  return -1;
}


//Method 2
//or we can swap the linked list instead of making another function
//below is my implementation


int getIntesectionNode(node* head1, node* head2)
{
  int c1 = getCount(head1);
  int c2 = getCount(head2);
  int d;
 
  if(c1 > c2)
  {
    d = c1 - c2;
  }
  if(c2>c1)
  {
	  node *temp;
	  temp=head1;
	  head1=head2;
	  head2=temp;
	  d=c2-c1;
  }

  int i;
  node* current1 = head1;
  node* current2 = head2;
	
  for(i = 0; i < d; i++)
  {
    if(current1 == NULL)
    {  
		return -1;
	}
    current1 = current1->next;
  }
 
  while(current1 !=  NULL && current2 != NULL)
  {
    if(current1 == current2)
      return current1->data;
    current1= current1->next;
    current2= current2->next;
  }
 
  return -1;
}
//count elements
int getCount(node* head)
{
  node* temp = head;
  int c= 0;
 
  while (temp != NULL)
  {
    c++;
    temp = temp->next;
  }
 
  return c;
}
//print elements 
void print(node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
} 

int main()
{
 
 
 /*
    Create two linked lists
 
    1st 3->6->9->15->30
    2nd 	 10->15->30
 
    15 is the intersection point
  */
 
  node* newNode;
  node* head1 =new node;
  head1->data  = 10;
  
  node* head2 =new node;
  head2->data  = 3;
 
  newNode = new node;
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = new node;
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = new node;
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
  //at this point they get merged
  newNode = new node;
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
  
  print(head1);
  print(head2);  
  printf("\nThe node of intersection is %d \n",
          getIntesectionNode(head2, head1));
 
}