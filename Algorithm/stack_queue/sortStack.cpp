/*
Sort the stack i.e if the stack is like 11 2 32 3 41 and top =41 so it should be converted into
41 32 11 3 2 and top should be 41

Input:
2
3
3 2 1
5
11 2 32 3 41

Output:
3 2 1
41 32 11 3 2
*/

#include<bits/stdc++.h>
using namespace std;

int fn(stack<int> s)
{
	int *a,i=0;
	int n=s.size();
	a=new int[n];
	while(!s.empty())
	{
		a[i++]=s.top();
		s.pop();
	}
	sort(a,a+n);
	i=0;
	while(n--)
	{
		s.push(a[i++]);
	}
}

int main()
{
	int p,n,e;
	stack<int> s;
	cin>>p;
	while(p--)
	{
		cin>>n;
		while(n--)
		{
			cin>>e;
			s.push(e);
		}
		fn(s);
	}
}