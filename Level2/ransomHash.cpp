/*
Hash Tables: Ransom Note
Input Format

The first line contains two space-separated integers describing the respective values of  (the number of words in the magazine) and  (the number of words in the ransom note). 
The second line contains  space-separated strings denoting the words present in the magazine. 
The third line contains  space-separated strings denoting the words present in the ransom note.

Each word consists of English alphabetic letters (i.e.,  to  and  to ).
The words in the note and magazine are case-sensitive.
Output Format

Print Yes if he can use the magazine to create an untraceable replica of his ransom note; otherwise, print No.

Sample Input 0
6 4
give me one grand today night
give one grand today

Sample Output 0
Yes

Sample Input 1
6 5
two times three is not four
two times two is four

Sample Output 1
No
*/


#include <bits/stdc++.h>
using namespace std;

bool ransom_note(string s1[],string s2[],int m,int n)
{
    if(n>m)
        return false;
    unordered_map<string ,int> mp;
    int i,j;
    for(i=0;i<m;i++)
        mp[s1[i]]++;
    for(i=0;i<n;i++)
    {
        if(mp.find(s2[i])!=mp.end())
        {
            if(mp[s2[i]]>0) mp[s2[i]]--;
            else return false;
        }
        else return false;
        
    }
    return true;
        
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    string s1[30000],s2[30000];
    for(int i=0;i<m;i++)
        cin>>s1[i];
    for(int i=0;i<n;i++)
        cin>>s2[i];
    if(ransom_note(s1,s2,m,n))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
