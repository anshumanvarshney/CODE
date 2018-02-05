/*
Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer
the above line is important in this question
*/

#include<bits/stdc++.h>
using namespace std;

int fn(int n)
{
	int sign=1;
	if (n < 0)//because we are dealing with max condition in overflow
	{
        sign = -1;
        n *= -1;
    }
	int r=0,d;
	while(n!=0)
	{
		d=n%10;
		if (r > (INT_MAX / 10) || (r == (INT_MAX / 10) && d > (INT_MAX % 10)))
			//overflow condition decided by the value ..how it goes r=n/10 and d=n&10
		{
            return 0;
        }
		r=r*10+d;
		n=n/10;
		
	}
    r *= sign;        
    return r;
}

/*
int rev = 0, sign = 1, digit;
    if (x < 0) {
        sign = -1;
        x *= -1;
    }
    while (x > 0) {
        digit = x%10;
        // check for overflow here 
        if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && digit > (INT_MAX % 10))) {
            return 0;
        }
        rev = rev * 10 + digit;
        x/=10;
    }
    rev *= sign;        
        return rev;
    }
*/

int main()
{
	int n;
	cin>>n;
	cout<<fn(n);
}