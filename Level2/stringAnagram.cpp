/*
Remove minimum number of characters so that two strings become anagram
Given two strings in lowercase, the task is to make them anagram.
 The only allowed operation is to remove a character from any string.
 Find minimum number of characters to be deleted to make both the strings anagram?
If two strings contains same data set in any order then strings are called Anagrams.

Examples:

Input : str1 = "bcadeh" str2 = "hea"
Output: 3
We need to remove b, c and d from str1.

Input : str1 = "cddgk" str2 = "gcd"
Output: 2

Input : str1 = "bca" str2 = "acb"
Output: 0
*/
#include <bits/stdc++.h>

using namespace std;

int number_needed(string a, string b) 
{
    int count1[26],count2[26],i,j;
    memset(count1,0,sizeof(count1));
    memset(count2,0,sizeof(count2));
    for(i=0;i<a.length();i++)
    {
        count1[a[i]-'a']++;
    }
    for(i=0;i<b.length();i++)
    {
        count2[b[i]-'a']++;
    }
    int res=0;
    for(i=0;i<26;i++)
        res+=abs(count1[i]-count2[i]);
    return res;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
