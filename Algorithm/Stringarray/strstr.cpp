
/*
Implement strstr
Example:
Input
2
GeeksForGeeks Fr
GeeksForGeeks For
Output
-1
5
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a="GeeksForGeeks";
	string b="Fr";
	if(a.find(b)!=string::npos)return a.find(b);
	else return -1;
}