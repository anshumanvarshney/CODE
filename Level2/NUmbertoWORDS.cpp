/*
Input:
2
2
142

Output:
two
one hundred and forty two
*/

#include <iostream>
using namespace std;
 
string one[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ","eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen "
               };//zero in space
 
string ten[] = { "", "", "twenty ", "thirty ", "fourty ",
                 "fifty ", "sixty ", "seventy ", "eighty ",
                 "ninety "
               };//0ty onety in space
			
string convert(int n,string s)
{
	string str="";
	if(n>19)
	{
		str+=ten[n/10]+one[n%10];
	}
	else str+=one[n];
	if(n!=0)
	{
		str+=s;
	}
	return str;
}
string ntw(int n)
{
	string out="";
	out+=convert((n/10000000),"crore ");
	out+=convert(((n/100000)%100),"lakh ");
	out+=convert(((n/1000)%100),"thousand ");
	out+=convert(((n/100)%10),"hundred ");
	if(n%100!=0&&n>100)
		out+="and ";
	out+=convert((n%100)," ");
	return out;
}
			
int main()
{
	int p;
	cin>>p;
	while(p--)
	{
		int n;
		//cout<<"Enter a number :";
		cin>>n;
		cout<<ntw(n)<<"\n";
	}
}