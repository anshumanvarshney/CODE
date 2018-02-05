/*
Given a positive integer, return its corresponding column title as it would appear in an Excel Spreadsheet.
For Example :

1 -> A
2 -> B
....
....
26 -> Z
27 -> AA
Input Format

One integer denoting the column number.

Constraints

The integer size will be less than 32-bits.

Output Format

Output the corresponding column title.

Sample Input 0

27
Sample Output 0

AA
*/

#include <bits/stdc++.h>
using namespace std;

string count(int a)
{
    string s="";
    while(a>0)//0=A here we consider
    {  
       a--;
       char c = (a%26)+'A';
       s = c+s;//here we are adding s at end think about it 
       a = a/26;
     }
    return s;
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a;
    cin>>a;
    cout<<count(a);
    return 0;
}