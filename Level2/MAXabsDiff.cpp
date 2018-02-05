/*
You are given an array of N integers A1, A2, A3... AN.
Your task is to write a program to print the maximum value f(i, j) for all 1 <= i,j <= N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes the absolute value of x.

Sample Input 0

3
1 3 -1
Sample Output 0

5
Explanation 0

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

hint

f(i, j) = |A[i] - A[j]| + |i - j| can be written in 4 ways (Since we are looking at max value, we don’t even care if the value becomes negative as long as we are also covering the max value in some way).

(A[i] + i) - (A[j] + j)
-(A[i] - i) + (A[j] - j) 
(A[i] - i) - (A[j] - j) 
(-A[i] - i) + (A[j] + j) = -(A[i] + i) + (A[j] + j)
*/

#include <bits/stdc++.h>
using namespace std;


int main() 

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int A[1000000],i,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
    int ans = INT_MIN;
    
    for (i = 0; i<n; ++i)
    {
        max1 = max(max1, A[i] + i);
        max2 = max(max2, -A[i] + i);
        max3 = max(max3, A[i] - i);
        max4 = max(max4, -A[i] - i);
    }
    for (i = 0; i<n; ++i)
    {
        ans = max(ans, max1 - A[i] - i);//+ + - - (reverse operation of every max)
        ans = max(ans, max2 + A[i] - i);//- + + - 
        ans = max(ans, max3 - A[i] + i);//+ - - +
        ans = max(ans, max4 + A[i] + i);//- - + + 
    }
   cout<<ans;
    
    return 0;
}

