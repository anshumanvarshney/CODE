/*
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

R_ _ _ _ _ _ 
_ _ _ _ _ _ _
_ _ _ _ _ _ *

The robot can only move either down or right at any point in time. The robot is trying to reach the
 bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)

			  
Algo: using dp
for m=2 and n=3


matrix:
  0	  1   2
0 1	  1	  1 i.e only one path if matrix is 1*3

1 1   2   3	
*/


#include<bits/stdc++.h>
using namespace std;

//my dp
int cntways(int m, int n)
{
    int ways[m][n];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(i == 0 || j == 0)
                ways[i][j] = 1;
            else
                ways[i][j] = ways[i-1][j] + ways[i][j-1];
        }
    }
     
    return ways[m-1][n-1];
}


//geek dp
int cntways(int m, int n)
{
    int ways[m][n];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(i == 0 && j == 0)
                ways[i][j] = 1;
            else if(i == 0)
                ways[i][j] = ways[i][j-1];
            else if(j == 0)
                ways[i][j] = ways[i-1][j];
            else
                ways[i][j] = ways[i-1][j] + ways[i][j-1];
        }
    }
     
    return ways[m-1][n-1];
}

int main()
{
   cout<<cntways(2,3);
   return 0;
}


/*
or using combination

Note that you have to take m + n - 2 steps in total. You have to take (m - 1) steps going down and (n-1) steps going right.

Let 0 denote a down step and 1 denote a right step.

So we need to find out the number of strings of length m + n - 2 which have exactly m - 1 zeroes and n - 1 ones.

Essentially we need to choose the positions of ‘1s’, and then ‘0s’ fall into the remaining positions.

So, the answer becomes Choose(m+n-2, n - 1).


int uniquePaths(int m, int n) {
            
			//formula  :   m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
            
			long long ans = 1;
            for (int i = n; i <= (m + n - 2); i++) {
                ans *= i;
                ans /= (i - n + 1);
            }
            return (int)ans;
        }
*/