/*		   
Binary representation of a given number
Write a program to print Binary representation of a given number.

Source: Microsoft Interview Set-3    					

Method 1: Iterative
For any number, we can check whether its ‘i’th bit is 0(OFF) or 1(ON) by bitwise ANDing it with “2^i” (2 raise to i).

1) Let us take number 'NUM' and we want to check whether it's 0th bit is ON or OFF	
	bit = 2 ^ 0 (0th bit)
	if  NUM & bit == 1 means 0th bit is ON else 0th bit is OFF

2) Similarly if we want to check whether 5th bit is ON or OFF	
	bit = 2 ^ 5 (5th bit)
	if NUM & bit == 1 means its 5th bit is ON else 5th bit is OFF.
Let us take unsigned integer (32 bit), which consist of 0-31 bits. 
To print binary representation of unsigned integer, start from 31th bit, 
check whether 31th bit is ON or OFF, if it is ON print “1” else print “0”. 
Now check whether 30th bit is ON or OFF, if it is ON print “1” else print “0”,
 do this for all bits from 31 to 0, finally we will get binary representation of number.


Method 2: Recursive
Following is recursive method to print binary representation of ‘NUM’.

step 1) if NUM > 1
	a) push NUM on stack
	b) recursively call function with 'NUM / 2'
step 2)
	a) pop NUM from stack, divide it by 2 and print it's remainder.
*/
#include<bits/stdc++.h>
using namespace std;

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)//2^31 give 32 bit number //this method is used to find ith bit is set or not
        (n & i)? printf("1"): printf("0");//if ith bit is set return 1 else return 0
}
 
int main(void)
{
    bin(7);//we get 00000000000000000000000000000000111 (total bit 31)
    printf("\n");
    bin(4);
}	

//or

void bin(unsigned n)
{
	while(n!=0)
	{
		cout<<n%2;
		n=n/2;
	}
}

void bin(unsigned n)
{
    /* step 1 */
    if (n > 1)
        bin(n/2);
 
    /* step 2 */
    printf("%d", n % 2);
}
/* 
int main(void)
{
    bin(7);
    printf("\n");
    bin(4);
}
*/