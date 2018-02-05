/*
Output Format

If Vasya managed to say hello, print "YES", otherwise print "NO".

Sample Input 0
ahhellllloou
Sample Output 0
YES

Sample Input 1
hlelo
Sample Output 1
NO
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string a="hello";
    string s;
    cin>>s;
    int i,j=0,c=0;
    for(i=0;i<s.length();i++)
    {
        if(s[i]==a[j])
        {
            j++;
            c++;
        }
    }
    if(c==5)
        cout<<"YES";
    else cout<<"NO";
    return 0;
}
