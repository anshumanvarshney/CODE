/*
Print all possible strings that can be made by placing spaces
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them.

Input:  str[] = "ABC"
Output: ABC
        AB C
        A BC
        A B C	
*/
void print(string ans,string s,int i)
{
	if(i==s.length())
	{	
		cout<<ans<<"$";
		return;
	}
	
	if(i==0)
         print(ans+s[i],s,i+1);
	else
	{
		print(ans+s[i],s,i+1);
		print(ans+" "+s[i],s,i+1);//it print AB C
	}
}
//given
void  printSpace(char str[])
{
    print("",str,0);
}

/*

Example:
Input:
2
AB
ABC

Output:
(A B)(AB)
(A B C)(A BC)(AB C)(ABC)

#include<bits/stdc++.h>
using namespace std;

void print(string ans,string &res,string s,int i)
{
	if(i==s.length())
	{	
		reverse(ans.begin(),ans.end());
		res+=")";
		res+=ans;
		res+="(";
		return;
	}
	
	if(i==0)
         print(ans+s[i],res,s,i+1);
	else
	{
		print(ans+s[i],res,s,i+1);
		print(ans+" "+s[i],res,s,i+1);//it print AB C
	}
}

int main()
 {
	//welcome Anshuman Varshney
	int p;
	cin>>p;
	while(p--)
	{
	    string s,res="";
	    cin>>s;
	    print("",res,s,0);
	    reverse(res.begin(),res.end());
	    cout<<res;
	    cout<<endl;
	}
	return 0;
}
*/
