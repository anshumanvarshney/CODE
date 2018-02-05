/*An approach that uses O(1) time and O(n) extra space

Question: Design a Data Structure SpecialStack that supports all the stack operations like 
push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element
 from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack,
 you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.
 
 Solution: Use two stacks: one to store actual stack elements and other as an auxiliary stack
 to store minimum values. The idea is to do push() and pop() operations in such a way that the 
 top of auxiliary stack is always the minimum. Let us see how push() and pop() operations work.

Push(int x) // inserts an element x to Special Stack 
1) push x to the first stack (the stack with actual elements)
2) compare x with the top element of the second stack (the auxiliary stack). Let the top element be y.
…..a) If x is smaller than y then push x to the auxiliary stack.

int Pop() // removes an element from Special Stack and return the removed element 
1) pop the top element from the auxiliary stack.
2) pop the top element from the actual stack and return it.

The step 1 is necessary to make sure that the auxiliary stack is also updated for future operations.

int getMin() // returns the minimum element from Special Stack 
1) Return the top element of auxiliary stack.

We can see that all above operations are O(1).
Let us see an example. Let us assume that both stacks are initially empty and 18, 19, 29, 15 and 16 are 
inserted to the SpecialStack.

When we insert 18, both stacks change to following.
Actual Stack
18 <--- top     
Auxiliary Stack
18 <---- top

When 19 is inserted, both stacks change to following.
Actual Stack
19 <--- top     
18
Auxiliary Stack
18 <---- top

When 29 is inserted, both stacks change to following.
Actual Stack
29 <--- top     
19
18
Auxiliary Stack
18 <---- top


When 15 is inserted, both stacks change to following.
Actual Stack
15 <--- top     
29
19 
18
Auxiliary Stack
15 <---- top
18

When 16 is inserted, both stacks change to following.
Actual Stack
16 <--- top     
15
29
19 
18
Auxiliary Stack
15 <---- top
18
*/

#include<bits/stdc++.h>
using namespace std;

class Stack
{
	private:
		static const int max = 100;
		int arr[max];
		int top;
	public:
		Stack() { top = -1; }
		bool isEmpty();
		bool isFull();
		int pop();
		void push(int x);
};
bool Stack::isEmpty()
{
    if(top == -1)//if empty
        return true;
    return false;
}
 
bool Stack::isFull()
{
    if(top == max - 1)//if full
        return true;
    return false;
}

int Stack::pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow";
        abort();
    }
    int x = arr[top];
    top--;
    return x;
}
 
void Stack::push(int x)
{
    if(isFull())
    {
        cout<<"Stack Overflow";
        abort();//note the uses of this function
    }
    top++;
    arr[top] = x;
}

//Auxillary Stack
class SpecialStack : public Stack//inherited
{
		Stack min;//object of actual stack 
	public:
		int pop();
		void push(int x);
		int getMin();
};
 
 
void SpecialStack::push(int x)
{
    if(isEmpty()==true)
    {
        Stack::push(x);//push in actual stack
        min.push(x);//push in auxilliary stack 
    }
    else
    {
        Stack::push(x);
        int y = min.pop();//pop from auxillary stack//
        min.push(y);//
  
        if( x <= y )
          min.push(x);
    }
}
 

int SpecialStack::pop()
{
    int x = Stack::pop();
    int y = min.pop();
 
    /* Push the popped element y  back only if it is not equal to x */
    if ( y != x )
      min.push(y);
 
    return x;
}
 
/* SpecialStack's member method to get minimum element from it. */
int SpecialStack::getMin()
{
    int x = min.pop();//or we can use top function to get it clear
    min.push(x);//because we have to print it only not to be deleted
    return x;
}
 
int main()
{
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.getMin()<<endl;
    s.push(5);
    cout<<s.getMin();
    return 0;
}
/*
output
10
5
*/