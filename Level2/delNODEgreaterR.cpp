/*
Delete nodes having greater value on right
Given a singly linked list, remove all the nodes which have a greater value on right side.

Input:
3
8
12 15 10 11 5 6 2 3
6
10 20 30 40 50 60
6
60 50 40 30 20 10

Output:

15 11 6 3
60
60 50 40 30 20 10

Algo:
use stack data structure to store node according to requiremnt
reverse the stack to get the answer
*/
/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

Node *reverse(Node *head)
{
    Node *prev,*curr,*next;
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
Node *compute(Node *head)
{
    stack<Node *> s;
    Node *t1,*t2;
    t1=head;
    while(t1!=NULL)
    {
        s.push(t1);
        t2=t1->next;
        while(t2!=NULL)
        {
            if(s.top()->data < t2->data)
            {
                s.pop();
                break;
            }
            t2=t2->next;
        }
        t1=t1->next;
    }
    Node *temp=s.top();
    s.pop();
    head=temp;
    while(!s.empty())
    {
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    temp->next=NULL;
    Node *h=reverse(head);
    return h;
}
