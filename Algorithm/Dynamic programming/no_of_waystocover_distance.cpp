/*
Count number of ways to cover a distance
Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.

Examples:

Input:  n = 3
Output: 4
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step

 
 
Input:  n = 4
1111
121
211
112
31
13
22
Output: 7

Algo :

The time complexity of above solution is exponential, a close upper bound is O(3n). 
If we draw the complete recursion tree, we can observer that many subproblems are solved again and again.
 For example, when we start from n = 6, we can reach 4 by subtracting one 2 times and by subtracting 2 one times.
 So the subproblem for 4 is called twice.
Since same suproblems are called again, this problem has Overlapping Subproblems property.
 So min square sum problem has both properties (see this and this) of a dynamic programming problem. 
 Like other typical Dynamic Programming(DP) problems, 
recomputations of same subproblems can be avoided by constructing a temporary array count[] in bottom up manner.
*/

/*

Generalization of the above problem
How to count number of ways if the person can climb up to m stairs for a given value m? For example if m is 4, the person can climb 1 stair or 2 stairs or 3 stairs or 4 stairs at a time.

We can write the recurrence as following.

   ways(n, m) = ways(n-1, m) + ways(n-2, m) + ... ways(n-m, m) 
*/

#include<bits/stdc++.h>
using namespace std;

int printCountDP(int dist)
{
    int count[dist+1];
 
    // Initialize base values. There is one way to cover 0 and 1
    // distances and two ways to cover 2 distance
    count[0]  = 1,  count[1] = 1,  count[2] = 2;//1+1 2
 
    // Fill the count array in bottom up manner
    for (int i=3; i<=dist; i++)
       count[i] = count[i-1]%1000000007 + count[i-2]%1000000007 + count[i-3]%1000000007;
 
    return count[dist]%1000000007;
}
 
/*
Recursion
 int printCountRec(int dist)
{
    // Base cases
    if (dist<0)    return 0;
    if (dist==0)  return 1;
 
    // Recur for all previous 3 and add the results
    return printCountRec(dist-1) +
           printCountRec(dist-2) +
           printCountRec(dist-3);// for dist =1 only (0)+(-1)+(-2)=1+0+0=1 , for dist =2 (1)+(0)+(-1)==((0)+(-1))+1+0==1+0+1+0==2
}

*/ 
 
 

// driver program
int main()
{
    int dist = 4;//1111 31 13 121 112 211 22
    cout << printCountDP(dist);//using dp
	//cout<<printCountRec(dist);//using recursion
    return 0;
}