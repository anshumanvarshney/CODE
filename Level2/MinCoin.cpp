/*
Find minimum number of coins that make a given value
Given a value V, if we want to make change for V cents, and we have infinite supply of each of
 C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?
Examples:

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents

The minimum number of coins for a value V can be computed using below recursive formula.

If V == 0, then 0 coins required.
If V > 0
   minCoin(coins[0..m-1], V) = min {1 + minCoins(V-coin[i])} 
                               where i varies from 0 to m-1 
                               and coin[i] <= V 
*/

int minCoins(int coins[], int m, int V)
{
   // base case
   if (V == 0) return 0;
 
   // Initialize result
   int res = INT_MAX;
 
   // Try every coin that has smaller value than V
   for (int i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
         int sub_res = minCoins(coins, m, V-coins[i]);
 
         // Check for INT_MAX to avoid overflow and see if
         // result can minimized
         if (sub_res != INT_MAX && sub_res + 1 < res)
            res = sub_res + 1;
     }
   }
   return res;
}

/*
The time complexity of above solution is exponential. If we draw the complete recursion tree,
 we can observer that many subproblems are solved again and again. For example, when we start from V = 11, 
we can reach 6 by subtracting one 5 times and by subtracting 5 one times. So the subproblem for 6 is called twice.
*/


#include<bits/stdc++.h>
using namespace std;

int count(int coins[],int m,int V)
{	// table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V+1];
    // Base case (If given value V is 0)
    table[0] = 0;
    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    if(table[V]==INT_MAX)
        return -1;
    return table[V];
}
int main()
 {
	//welcome Anshuman Varshney
	int p;
	cin>>p;
	while(p--)
	{
	    int n,k,i,c=0;
	    cin>>k>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	        cin>>a[i];
	   cout<<count(a,n,k)<<"\n";
	}
	return 0;
}