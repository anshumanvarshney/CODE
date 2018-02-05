/*
Queue using two stack

The problem is opposite of this post. We are given a stack data structure with push and pop operations, 
the task is to implement a queue using instances of stack data structure and operations on them.

Stack and Queue with insert and delete operations

In this challenge, you must first implement a queue using two stacks. Then process  queries,
 where each query is one of the following  types:

1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.

Sample Input

10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2
Sample Output

14
14


A queue can be implemented using two stacks. Let queue to be implemented be q and 
stacks used to implement q be stack1 and stack2. q can be implemented in two ways:


Method 1 (By making enQueue operation costly) This method makes sure that oldest entered element is always
 at the top of stack 1, so that deQueue operation just pops from stack1. To put the element at top of stack1, stack2 is used.

enQueue(q, x)
  1) While stack1 is not empty, push everything from satck1 to stack2.
  2) Push x to stack1 (assuming size of stacks is unlimited).
  3) Push everything back to stack1.

dnQueue(q)
  1) If stack1 is empty then error
  2) Pop an item from stack1 and return it
Method 2 (By making deQueue operation costly)In this method, in en-queue operation, the new element is entered at
 the top of stack1. In de-queue operation, if stack2 is empty then all the elements are moved to stack2 and 
 finally top of stack2 is returned.
enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) Pop the element from stack2 and return it.
Method 2 is definitely better than method 1.
Method 1 moves all the elements twice in enQueue operation, while method 2 (in deQueue operation) moves the
 elements once and moves elements only if stack2 empty.
*/

#include<bits/stdc++.h>
using namespace std;

class sq
{
	private:
		stack<int> s1;
		stack<int> s2;
	public:
		void push(int x);
		void pop();
		void print();
};

void sq::push(int x)
{
	s1.push(x);
}
/*
the method is correct but time coplexity is increased

void sq::pop()
{
	while(!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	//cout<<s2.top()<<" ";
	s2.pop();
	while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
}

void sq::print()
{
	while(!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	cout<<s2.top()<<"\n";
	while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
}*/
void sq::pop()
{
    int ret;
		if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
       
        if(!s2.empty())
        {
            ret = s2.top();
            s2.pop();
        }
        
}

void sq::print()
{
		if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int ret = -1;
        
        if(!s2.empty())
        {
            ret = s2.top();
        }
        
        cout<<ret<<"\n";
}

*/
int main()
{
	sq o;
	int p,n,x,i,e;
	cin>>p;
	while(p--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>x;
			if(x==1)
			{
				cin>>e;
				o.push(e);
			}
			else if(x==2)
				o.pop();
			else if(x==3)
				o.print();
		}
	}
}