/*
Find an equal point in a string of brackets
Given a string of brackets, the task is to find an index k which decides the number of opening brackets 
is equal to the number of closing brackets.
String must be consists of only opening and closing brackets i.e. ‘(‘ and ‘)’.

An equal point is an index such that the number of opening brackets before it is equal to the number of
 closing brackets from and after.

Examples:

Input : str = "(())))("
Output:   4
After index 4, string splits into (())
and ))(. Number of opening brackets in the 
first part is equal to number of closing 
brackets in the second part.

Input : str = "))"
Output: 2
As after 2nd position i.e. )) and "empty"
string will be split into these two parts:
So, in this number of opening brackets i.e.
0 in the first part is equal to number of 
closing brackets in the second part i.e. 
also 0.
*/
/*
Example:
Input:
2
(())))(
))
Output:
4
2
*/
//my algo
//1 //some test case missing
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j;
	string s="))";
	i=0,j=s.length()-1;
	while(i<j)
	{
		while(s[i]!='('&&i<j) i++;
		while(s[j]!=')'&&i<j) j--;
		i++,j--;
	}
	cout<<i;
}

//2
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,p,c;
	cin>>p;
	while(p--)
	{
	    c=0;
    	string s;
    	cin>>s;
	    for(i=0;i<s.length();i++)
	    {
	        if(s[i]=='(')
	            c++;
	    }
	    cout<<s.length()-c<<"\n";
	}
}



#include<bits/stdc++.h>
using namespace std;

int check(string a)
{	
	int result=-1;
	int n=a.length();
	int *open,*close,i,j;
	open=new int[n];
	close=new int[n];
	memset(open,0,sizeof(open));
	memset(close,0,sizeof(close));
	if(a[0]=='(')
		open[0]=1;
	if(a[n-1]==')')
		close[n-1]=1;
	for(i=1;i<n;i++)
	{
		if(a[i]=='(')
			open[i]=open[i-1]+1;
		else open[i]=open[i-1];
	}
	for(i=n-2;i>=0;i--)
	{
		if(close[i]==')')
			close[i]=close[i+1]+1;
		else close[i]=close[i+1];
	}
	if(open[n-1]==0)
		return n;
	if(close[0]==0)
		return 0;
	for (i=0; i<n; i++)
        if (open[i] == close[i])
            result=i;

	return result; 
}

int main()
{
	int n,p;
	string a;
	cin>>p;
	while(p--)
	{
		cin>>a;
		cout<<check(a);
	}
}