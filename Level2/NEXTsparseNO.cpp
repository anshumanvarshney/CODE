/*
Find Next Sparse Number
A number is Sparse if there are no two adjacent 1s in its binary representation. 
For example 5 (binary representation: 101) is sparse, but 6 (binary representation: 110) is not sparse.
Given a number x, find the smallest Sparse number which greater than or equal to x.

Examples:

Input: x = 6
Output: Next Sparse Number is 8

Input: x = 4
Output: Next Sparse Number is 4

Input: x = 38
Output: Next Sparse Number is 40

Input: x = 44
Output: Next Sparse Number is 64

A Simple Solution is to do following:

1) Write a utility function isSparse(x) that takes a number 
   and returns true if x is sparse, else false.  This function
   can be easily written by traversing the bits of input number.
2) Start from x and do following 
   while(1)
   {
      if (isSparse(x))
         return x;
      else 
         x++
   }
Time complexity of isSparse() is O(Log x). Time complexity of this solution is O(x Log x).
 The next sparse number can be at most O(x) distance away.

An Efficient Solution can solve this problem without checking all numbers on by one. Below are steps.

1) Find binary of the given number and store it in a 
   boolean array.
2) Initialize last_finalized bit position as 0.
2) Start traversing the binary from least significant bit.
    a) If we get two adjacent 1's such that next (or third) 
       bit is not 1, then 
          (i)  Make all bits after this 1 to last finalized
               bit (including last finalized) as 0. 
          (ii) Update last finalized bit as next bit. 
For example, let binary representation be 01010001011101, we change it to 01010001100000
 (all bits after highlighted 11 are set to 0). Again two 1’s are adjacent, 
so change binary representation to 01010010000000. This is our final answer.
*/
#include <bits/stdc++.h>
using namespace std;
 
//MY ALGO
int isSparse(int x)
{
	int b[100],i=0;//take B as big as possible	
	while(x!=0)
	{
		b[i++]=x%2;
		x=x/2;
	}
	for(int j=0;j<i-1;j++)
	{
		if(b[j]==1&&b[j+1]==1)
			return 0;
	}
	return 1;
}
 
int main()
{
	int x;
	cin>>x;
	int t=2*x;
	while(x<t)
	{
		int t=x;
      if (isSparse(x)==1)
	  {
         cout<<t;
		 break;
	  }
      else 
         x++;
	}
}
