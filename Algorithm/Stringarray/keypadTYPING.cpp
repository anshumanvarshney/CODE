/*
Keypad Typing

You are given N strings of alphabet characters and the task is to find their matching decimal representation 
as on the shown keypad. Output the decimal representation corresponding to the string. 
For ex: if you are given “amazon” then its corresponding decimal representation will be 262966.
Example:

Input
2
geeksforgeeks
geeksquiz

Output
4335736743357
433577849
*/
//keypad typing
#include<bits/stdc++.h>
using namespace std;

int fn(char a)
{
	if(a=='a'||a=='b'||a=='c')
		return 2;
	else if(a=='d'||a=='e'||a=='f')
		return 3;
	else if(a=='g'||a=='h'||a=='i')
		return 4;
	else if(a=='j'||a=='k'||a=='l')
		return 5;
	else if(a=='m'||a=='n'||a=='o')
		return 6;
	else if(a=='p'||a=='q'||a=='r'||a=='s')
		return 7;
	else if(a=='t'||a=='u'||a=='v')
		return 8;
	else if(a=='w'||a=='x'||a=='y'||a=='z')
		return 9;
}


int main()
{
	string a;
	int i,p;
	cin>>p;
	while(p--)
	{
		cin>>a;
		for(i=0;i<a.length();i++)
		{
			cout<<fn(a[i]);
		}
		cout<<"\n";
	}
}