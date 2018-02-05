/*
Stack using two queue

A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)


Example:
Input
1
5
1 2 1 3 2 1 4 2   

Output
3 4

Version A (efficient push):

push:
enqueue in queue1
pop:
while size of queue1 is bigger than 1, pipe dequeued items from queue1 into queue2
dequeue and return the last item of queue1, then switch the names of queue1 and queue2

Version B (efficient pop):

push:
enqueue in queue2
enqueue all items of queue1 in queue2, then switch the names of queue1 and queue2
pop:
deqeue from queue1
*/



#include<bits/stdc++.h>
using namespace std;

class sq
{
	private:
		queue<int> q1;
		queue<int> q2;
	public:
		void push(int x);
		int pop();
		void swapp(queue<int> a,queue<int> b);
};

void sq::push(int x)
{
	q1.push(x);
}



int sq::pop()
{
    int ret=-1;
    while(q1.size()>1)
	{
		q2.push(q1.front());
		q1.pop();
	}
	if(!q1.empty())
	{
		ret=q1.front();
		q1.pop();
		swap(q1,q2);
		/*
		or
		
		queue<int> t=q1;
		q1=q2;
		q2=t;
		
		*/
	}
    return ret; 
}

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
				cout<<o.pop()<<" ";
		}
	}
}