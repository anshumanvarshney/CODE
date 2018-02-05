/*
Check for subsequence in O(n)

Given two strings a and b, find if a is a subsequence of b

Input: a = "axy", b = "yadxcp"
Output: 0 (a is not a subsequence of b)

Input: a = "gksrek", b = "geeksforgeeks"
Output: 1 (str1 is a subsequence of str2)
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
	    string a, b;
	    cin>>a>>b;
	    int n=a.size();
	    int m=b.size();
	    int i=0,j=0,c=0;
	   while(i<n && j<m)
	   {
	       if(a[i]!=b[j])
	            j++;
	       else i++;
	   }
	   if(i==n)
	     cout<<1;
	   else cout<<0;
	   cout<<"\n";
	}
	return 0;
}