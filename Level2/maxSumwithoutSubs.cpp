/*
Max Sum without Adjacents

Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that 
no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10)
or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//welcome Anshuman Varshney
	int p;
	cin>>p;
	while(p--)
	{
	    int n,i,s1=0,s2=0;
	    int a[500];
	    cin>>n;
	    for(i=0;i<n;i++)
	        cin>>a[i];
	    int dp[n + 1];
        dp[1] = a[0];
        dp[0] = 0;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 2] + a[i - 1], dp[i - 1]);
        }
	    cout<<dp[n]<<"\n";
	}
	return 0;
}