/*
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. 
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
So a string of length n has 2^n different possible subsequences.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.


DP
method:
1-first form a matrix with size+ index of both col and rows 
i.e
X= A G G T A B   so, m=6
Y= G X T X A Y B so, n=7

make a matrix L[m+1[n+1];
m+1=8(ie. 0 to 7)
n+1=7(ie. 0 to 6)
		
			G	X	T	X	A	Y	B

	XY	0 	1	2	3	4	5	6	7
		
	0  	0	0	0	0	0	0	0	0

A	1       0

G	2	0

G	3	0

T	4	0

A	5	0

B	6	0

2-then assign 0  whereever i=0,j=0 because when  first string is empty then the LCS is 0 so according to question
 like here we can assign zero  
we need to start 0 1 2 3 4 5 6 like this when we have to find no. of difference like so basically acc to condition 
we need to fill initial matrix when i=j=0
3-now from 1 onwards write letter on top
and compare with the given condition to fill matrix 
like we did in this question 
from G in col and row having AGGTAB we get only 1 LCS when G in col and row
and so on
*/
//using dp
#include<bits/stdc++.h>
  
int max(int a, int b);
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)//0's condition falls here i.e first row and first column is 0  then j=i=1;
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;//diagonal +1
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);//max(left and top) fn calls
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}
  
/*
recursive it uses m and n because it uses stack

int lcs( char *X, char *Y, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs(X, Y, m-1, n-1);
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
*/  
  
/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}
  
/* Driver program to test above function */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  
  int m = strlen(X);
  int n = strlen(Y);
  
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
 
  return 0;
}
