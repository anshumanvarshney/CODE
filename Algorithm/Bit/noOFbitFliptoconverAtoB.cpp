/*
Count number of bits to be flipped to convert A to B

Question: You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

Solution:

  1. Calculate XOR of A and B.      
        a_xor_b = A ^ B
  2. Count the set bits in the above calculated XOR result.
        countSetBits(a_xor_b)
XOR of two number will have set bits only at those places where A differs from B.

Example:

   A  = 1001001
   B  = 0010101
   a_xor_b = 1011100
   No of bits need to flipped = set bit count in a_xor_b i.e. 4
*/

#include<bits/stdc++.h>
using namespace std;

int bin(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
    count+=n%2;//count += n & 1;
    n=n/2;//n >>= 1;
  }
  return count;
	
}

int myXOR(int x, int y)
{
   return (x &~ y) | (~x & y);//return (x | y) & (~x | ~y);//flip flop logic orreturn ~((a&b)|(~a&~b)); 
}
int main()
{
	int a,b,sum=0;
	cin>>a>>b;
	
	//int t=(a^b);//using operator
	int t=myXOR(a,b);
	cout<<bin(t);
}

/*
A Better Solution can find XOR without using loop.

1) Find bitwise OR of x and y (Result has set bits where either x has set or y has set bit). 
OR of x = 3 (011) and y = 5 (101) is 7 (111)

2) To remove extra set bits find places where both x and y have set bits. 
The value of expression “~x | ~y” has 0 bits wherever x and y both have set bits.

3) bitwise AND of “(x | y)” and “~x | ~y” produces the required result.

Below is C++ implementation.

// C++ program to find XOR without using ^
#include <iostream>
using namespace std;
 
// Returns XOR of x and y
int myXOR(int x, int y)
{
   return (x &~ y) | (~x & y);//return (x | y) & (~x | ~y);//flip flop logic
}
 
// Driver program to test above function
int main()
{
   int x = 3, y = 5;
   cout << "XOR is " << myXOR(x, y);
   return 0; 
}

1. Simple Method Loop through all bits in an integer, check if a bit is set and if it is
 then increment the set bit count. See below program.


unsigned int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
 

int main()
{
    int i = 9;
    printf("%d", countSetBits(i));
    getchar();
    return 0;
}
*/