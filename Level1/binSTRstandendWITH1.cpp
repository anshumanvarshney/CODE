/*
Given a binary string, count number of substrings that start and end with 1.
For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.

Source: Amazon Interview Experience | Set 162

Input:
1
4
1111
Output:
6
*/
/*
simple algo
nC2 i.e n(n-1)/2
*/
n=4
char *a=new char[n+1];
for(i=0;i<n;i++)
	cin>>a[i];
c=0;
for(i=0;i<n;i++)
{
	if(a[i]=='1')
		c++;
}
cout<<c*(c-1)/2;



