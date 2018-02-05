/*
Given a permutation of number from 1 to N. Among all the subarrays, 
find the number of unique pairs (a,b) such that a≠b and a is maximum and b is second maximum in that subarray.

Sample Input 0

5
1 2 3 4 5
Sample Output 0

4

All possible subarrays are :
1
1 2
1 2 3 
1 2 3 4 
1 2 3 4 5
2
2 3
2 3 4
2 3 4 5
3
3 4
3 4 5
4
4 5
5

The 4 unique pairs are : 
(2, 1)
(3, 2)
(4, 3)
(5, 4)
*/

#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int n, ans = 0, a;
	stack <int> s;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a;
		while(!s.empty() and a > s.top())
		{
			s.pop();
			ans++;
		}
		if(!s.empty()) 
		  ans++;
		s.push(a);
	}
	cout << ans << endl;
	return 0;
}
/*
take eg: 5 1 2 3 4
*/