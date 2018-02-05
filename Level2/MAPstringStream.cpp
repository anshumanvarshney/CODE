/*
You have just moved from Chennai to a big livable city (... ... ... ).
The people here speak an incomprehensible dialect of a foreign language. Fortunately, 
you have a dictionary to help you understand them.

Input Format
Input consists of up to 100,000 dictionary entries, followed by a blank line, followed by a message
 of up to 100,000 words. Each dictionary entry is a line containing an English word, followed by a 
 space and a foreign language word. No foreign word appears more than once in the dictionary.
 The message is a sequence of words in the foreign language, one word on each line. Each word in the input
 is a sequence of at most 10 lowercase letters.

Output Format
Output is the message translated to English, one word per line. Foreign words not in the dictionary
 should be translated as ‘eh’.

Sample Input 
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay

Sample Output 

cat
eh
loops
*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s,r;
     map<string,string> m;
    int c=0;
        while(getline(cin,s))
        {
             
            if(s.length()==0||s.length()==1)
                break;  
            stringstream ss(s); 
            string s1,s2;
            ss>>s1>>s2;
                m[s2]=s1;
                
        }

    while(cin>>r)
    {
        if(m.find(r)!=m.end())
            cout<<m[r]<<"\n";
        else cout<<"eh\n";
    }
        
    return 0;
}