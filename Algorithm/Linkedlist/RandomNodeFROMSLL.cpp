/*
Select a Random Node from a Singly Linked List
Given a singly linked list, select a random node from linked list 
(the probability of picking a node should be 1/N if there are N nodes in list). 
You are given a random number generator.

How to select a random node with only one traversal allowed?
The idea is to use Reservoir Sampling. Following are the steps.
 This is a simpler version of Reservoir Sampling as we need to select only one key instead of k keys.

(1) Initialize result as first node
   result = head->key 
(2) Initialize n = 2
(3) Now one by one consider all nodes from 2nd node onward.
    (3.a) Generate a random number from 0 to n-1. 
         Let the generated random number is j.
    (3.b) If j is equal to 0 (we could choose other fixed number 
          between 0 to n-1), then replace result with current node.
    (3.c) n = n+1
    (3.d) current = current->next

*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *link;
};

node *newnode(int data)
{
	node *temp;
	temp=new node;
	temp->data=data;
	temp->link=NULL;
	return temp;
}

void printRandom(struct node *head)
{
    // IF list is empty
    if (head == NULL)
       return;
 
    // Use a different seed value so that we don't get
    // same result each time we run this program
    srand(time(NULL));
 
    // Initialize result as first node
    int result = head->data;
 
    // Iterate from the (k+1)th element to nth element
    node *temp = head;
    int n=2;
    while(temp!=NULL)
    {
        // change result with probability 1/n
		//Generate a random number from 0 to n-1. 
		int t=rand() % n;
		//cout<<t<<" ";to check random nuber generation
        if ( t== 0)
           result = temp->data;
 
        // Move to next node
        temp = temp->link;
		n++;
    }
 
    printf("Randomly selected key is %d\n", result);
}
void disp(node *head)
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}

int main()
{
	node *head;
	head=newnode(2);
	head->link=newnode(3);
	head->link->link=newnode(4);
	head->link->link->link=newnode(5);
	head->link->link->link->link=newnode(6);
	head->link->link->link->link->link=newnode(7);
	head->link->link->link->link->link->link=newnode(8);
	head->link->link->link->link->link->link->link=newnode(9);
	head->link->link->link->link->link->link->link->link=newnode(10);
	//disp(head);
	printRandom(head);
	
}

/*
How does this work?
Let there be total N nodes in list. It is easier to understand from last node.

The probability that last node is result simply 1/N [For last or N’th node,
 we generate a random number between 0 to N-1 and make last node as result if 
 the generated number is 0 (or any other fixed number]

The probability that second last node is result should also be 1/N.

The probability that the second last node is result 
          = [Probability that the second last node replaces result] X 
            [Probability that the last node doesn't replace the result] 
          = [1 / (N-1)] * [(N-1)/N]
          = 1/N
Similarly we can show probability for 3rd last node and other nodes.
*/