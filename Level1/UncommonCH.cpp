/*
Uncommon characters

Find and print the uncommon characters of the two given strings. Here uncommon character means that 
either the character is present in one string or it is present in other string but not in both. 
The strings contain only lowercase characters and can contain duplicates.

Example:
Input:
1
characters
alphabets

Output:
bclpr
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
	    string s1,s2;
	    cin>>s1>>s2;
	    int c1[1000],c2[1000],i;
	    
	    memset(c1,0,sizeof(c1));
	    memset(c2,0,sizeof(c2));
	    
	    for(i=0;i<s1.length();i++)
	        c1[s1[i]-'a']++;
	    
	    for(i=0;i<s2.length();i++)
	        c2[s2[i]-'a']++;     
	    
	    for(i=0;i<26;i++)
	    {
	        if(c1[i]==0 && c2[i]!=0)
	            cout<<char(i+'a');
	        if(c2[i]==0 && c1[i]!=0)
	            cout<<char(i+'a');     
	    }
	    cout<<"\n";
	}
	return 0;
}