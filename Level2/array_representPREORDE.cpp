/*
Check if a given array can represent Preorder Traversal of Binary Search Tree
Given an array of numbers, return true if given array can represent 
preorder traversal of a Binary Search Tree, else return false. Expected time complexity is O(n).

Examples:

Input:  pre[] = {2, 4, 3}
Output: true
Given array can represent preorder traversal
of below tree
    2
     \
      4
     /
    3

Input:  pre[] = {2, 4, 1}
Output: false
Given array cannot represent preorder traversal
of a Binary Search Tree.

Input:  pre[] = {40, 30, 35, 80, 100}
Output: true
Given array can represent preorder traversal
of below tree
     40
   /   \
 30    80 
  \      \
  35     100 


Input:  pre[] = {40, 30, 35, 20, 80, 100}
Output: false
Given array cannot represent preorder traversal
of a Binary Search Tree.

my algo:
store preorder traversal in array;
compare with given array

Algo mine:
take min of first two element then if further array contains <min then false else true
fails for 30 25 36 40 32 26 33 27 37 34 28 29 38 35 39 31 

An Efficient Solution can solve this problem in O(n) time. The idea is to use a stack. 
This problem is similar to Next (or closest) Greater Element problem. 
Here we find next greater element and after finding next greater, if we find a smaller element, then return false.

1) Create an empty stack.
2) Initialize root as INT_MIN.
3) Do following for every element pre[i]
     a) If pre[i] is smaller than current root, return false.
     b) Keep removing elements from stack while pre[i] is greater
        then stack top. Make the last removed item as new root (to
        be compared next).
        At this point, pre[i] is greater than the removed root
        (That is why if we see a smaller element in step a), we 
        return false)
     c) push pre[i] to stack (All elements in stack are in decreasing
        order)  
*/
#include<bits/stdc++.h>
using namespace std;
 
bool canRepresentBST(int pre[], int n)
{
    // Create an empty stack
    stack<int> s;
 
    // Initialize current root as minimum possible value
    int root = INT_MIN;
 
    // Traverse given array
    for (int i=0; i<n; i++)
    {
        // If we find a node who is on right side and smaller than root, return false
        if (pre[i] < root)
            return false;
		/*
		or 
		if(!.s.empty()&&root>s.top())
			return false;
		*/
        // If pre[i] is in right subtree of stack top,Keep removing items smaller than pre[i]
        // and make the last removed item as new root.
        while (!s.empty() && s.top()<pre[i])
        {
            root = s.top();
            s.pop();
        }
 
        // At this point either stack is empty or pre[i] is greater than root, push pre[i]
        s.push(pre[i]);
    }
    return true;
}
 
// Driver program
int main()
{
    int pre1[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre1)/sizeof(pre1[0]);
    canRepresentBST(pre1, n)? cout << "true\n":
                              cout << "false\n";
 
    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre2)/sizeof(pre2[0]);
    canRepresentBST(pre2, n)? cout << "true\n":
                              cout << "false\n";
 
    return 0;
}
/*
int main()
{
	int a[]={2, 4, 3};
	int n=sizeof(a)/sizeof(int);
	int flag=0,min;
	if(a[0]<a[1])
		min=a[0];
	else min=a[1];
	for(int i=2;i<n;i++)
	{
		if(a[i]<min)
		{
			flag=1;
		}
	}
	if(flag==1)
		cout<<"\nNot represent preorder";
	else cout<<"\nrepresent preorder";		
}*/