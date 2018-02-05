/*
Power Of Two Integers
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed
 as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 

*/

#include<bits/stdc++.h>
using namespace std;

//my algo
bool isPower(int x) 
{
    if (x <= 1) return true;
	long int a,b;
	a=2;
	b=2;
	int i;
	for(i=a;i<x;i++)
	{
		while(pow(i,b)<=x)
		{
			if(pow(i,b)==x)
				return true;
			else b++;
		}
		b=2;
	}
	return false;
}
//orwithout using pow function
bool isPower(int x) {
     
    if (x <= 1) return true;
     
    for (int i = 2; i < x ; i++)
	{
        long int temp = i; 
        while (temp <= x)
		{
            temp *= i;
            if (temp == x) return true;
        }
    }
     
    return false;
}

int main()
{
	int a;
	a=9;
    if(isPower(a))
		cout<<"Yes";
	else cout<<"No";
}