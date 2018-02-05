/*
Compute nCr % p | Set 2 (Lucas Theorem)
Given three numbers n, r and p, compute value of nCr mod p.

Examples:

Input:  n = 10, r = 2, p = 13
Output: 6
Explanation: 10C2 is 45 and 45 % 13 is 6.

Input:  n = 1000, r = 900, p = 13
Output: 8

A Simple Solution is to first compute nCr, then compute nCr % p.
 This solution works fine when the value of nCr is small.

What if the value of nCr is large?
refer theory first.

we use dp here because here occurs overlapping subproblems
eg 4,2
we have to compute two time 2,1
so .....to avoid recomputing we use dp
*/


// A Lucas Theorem based solution to compute nCr % p
#include<bits/stdc++.h>
using namespace std;
 
// Returns nCr % p.  In this Lucas Theorem based program,
// this function is only called for n < p and r < p.
int nCrModpDP(int n, int r, int p)
{
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    int C[r+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; // Top row of Pascal Triangle
 
    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++)
    {
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)
 
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
 
// Lucas Theorem based function that returns nCr % p
// This function works like decimal to binary conversion
// recursive function.  First we compute last digits of
// n and r in base p, then recur for remaining digits
/*int nCrModpLucas(int n, int r, int p)
{
   // Base case
   if (r==0)
      return 1;
 
   // Compute last digits of n and r in base p
   int ni = n%p, ri = r%p;
 
   // Compute result for last digits computed above, and
   // for remaining digits.  Multiply the two results and
   // compute the result of multiplication in modulo p.
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits
}*/
 
// Driver program
int main()
{
    int n = 1000, r = 900, p = 13;
    cout << "Value of nCr % p is " << nCrModpDP(n, r, p);
	//cout << "Value of nCr % p is " << nCrModpLucas(n, r, p);
    return 0;
}

/*
Time Complexity: Time complexity of this solution(hidden solution) is O(p2 * Logp n). 
There are O(Logp n) digits in base p representation of n. Each of these digits 
is smaller than p, therefore, computations for individual digits take O(p2).
 Note that these computations are done using DP method(shown method) which takes O(n*r) time.
*/