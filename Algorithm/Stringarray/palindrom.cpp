/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Example:
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

#include<bits/stdc++.h>
using namespace std;
/*
only for a word

string palind(string A)
{
	 int i = 0, j = A.length()-1;
    while (i<j)
    {
        if(tolower(A[i++])!=tolower(A[j--]))
            return "no";
        
    }
    return "yes";
}
*/
// perfect for all string type
string palind(string A)
{
	 int i = 0, j = A.length()-1;
    while (i<j)
    {
        while(i<j && !isalnum(A[i])) i++;
        while(i<j && !isalnum(A[j])) j--;
        if(tolower(A[i++])!=tolower(A[j--]))
            return "no";
        
    }
    return "yes";
}

int main()
{
	string a;
	cin>>a;
	cout<<palind(a);
	return 0;
}