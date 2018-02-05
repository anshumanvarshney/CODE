/*
0-1 Knapsack Problem

Given weights and values of n items, put these items in a knapsack of cap acity W to get the maximum 
total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] 
which represent values and weights associated with n items respectively. Also given an integer W
 which represents knapsack capacity, find out the maximum value subset of val[] such that sum of 
 the weights of this subset is smaller than or equal to W.
0-1 means  You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 
 */
 
 /*
 let W=7;
 w[]={1,3,4,5};
 v[]={1,4,5,7};
 
 initially all the weight is 0 because capacity is zero
			1	2	3	4	5	6	7(W)
 v	w	0	0	0	0	0	0	0	0
 1	1	0	1	1	1	1	1	1	1
 4	3	0	1	1	4	5	5	5	5	i.e. max((v[i-1]+k[i-1][j-wt[i-1],k[i-1][j])
 5	4	0	1	1	4	5	6	6	9
 7	5	0	1	1	4	5	7	8	9
 
 */
 
 // A Dynamic Programming based solution for 0-1 Knapsack problem
#include<stdio.h>
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   int i, j;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= W; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (wt[i-1] <= j)//compare with knapsackweight j include wieght
                 K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);
           else
                 K[i][j] = K[i-1][j];
       }
   }
   return K[n][W];
}
 
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
/*
Run on IDE
//i.e wt= (20+30)<=50 and the corresponding value = 100+120 =220
Output:
220
Time Complexity: O(nW) where n is the number of items and W is the capacity of knapsack.
*/