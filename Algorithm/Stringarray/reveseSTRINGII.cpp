/*
Reverse words in a given string
Example: Let the input string be “i like this program very much”. The function should change the string
 to “much very program this like i”
Examples :

Input  : s = "geeks quiz practice code"
Output : s = "code practice quiz geeks"

Input  : s = "getting good at coding needs a lot of practice"
Output : s = "practice of lot a needs coding at good getting"

Algorithm:

1) Reverse the individual words, we get the below string.
     "i ekil siht margorp yrev hcum"
2) Reverse the whole string from start to end and you get the desired output.
     "much very program this like i"
*/


#include<bits/stdc++.h>
using namespace std;

string reverseWords(string &s)
{
	string curr="";
	string add="";
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]!=' ')
			curr.push_back(s[i]);
		else if(curr.length()!=0)
		{
			reverse(curr.begin(),curr.end());
			if(add.length()>0)
				add+=' ';
			add+=curr;
			curr="";
		}		
	}
	if(curr.length()!=0)
		{
			reverse(curr.begin(),curr.end());
			if(add.length()>0)
				add+=' ';
			add+=curr;
		}
		reverse(add.begin(),add.end());
	return add;
}

int main()
{
	string s ="geeks quiz practice code";
	cout<<reverseWords(s);
	return 0;
}

/*
Reverse words in a given string

Given a String of length N reverse the words in it. Words are separated by dots.
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
*/

#include<bits/stdc++.h>
using namespace std;

string rev(string a)
{
	string x="";
	string y="";
	int n=a.length();
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]!='.')
		{
			x.push_back(a[i]);
		}
		else
		{
			reverse(x.begin(),x.end());
			x.push_back(a[i]);
			y+=x;
			x="";
		}
	}
	if(x.length()>0)
	{
		reverse(x.begin(),x.end());
		y+=x;
	}
	reverse(y.begin(),y.end());
	return y;
}

int main()
{
	int p;
	cin>>p;
	while(p--)
	{
		string a;
		cin>>a;
		cout<<rev(a);
	}
}
