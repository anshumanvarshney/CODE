/*
Check if string is rotated by two places

Given two strings, the task is to find if a string ('a') can be obtained by rotating another string ('b') by two places.
Examples:

Input : a = "amazon" 
        b = "azonam"  // rotated anti-clockwise
Output : 1

Input : a = "amazon"
        b = "onamaz"  // rotated clockwise
Output : 1
*/

#include<bits/stdc++.h>
using namespace std;

int check(string a,string b)
{
	int i;
	string c;
	c=a;
	reverse(c.begin(),c.begin()+2);
	reverse(c.begin()+2,c.end());
	reverse(c.begin(),c.end());
	if(c==b)
		return 1;
	c=a;
	reverse(c.begin(),c.end());
	reverse(c.begin(),c.begin()+2);
	reverse(c.begin()+2,c.end());
	if(c==b)
		return 1;
	return 0;
}

int main()
{
	string a,b;
	fsbcnuvqhffbsaqxwp
	//wpfsbcnuvqhffbsaqx
	cin>>a;
	cin>>b;
	cout<<check(a,b)<<"\0";
}