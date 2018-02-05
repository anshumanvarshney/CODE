/*
Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000
return 3221225472
*/

#include<bits/stdc++.h>
using namespace std;

//my method
int reverseBits(unsigned int a)
{
	int j=31;
	unsigned int n=0;
	for(int i=0;i<j;i++)
	{
		if(a & (1<<i))
		{
			n=n| (1<<(j-i));
			
		}
	}
	return n;
}


unsigned int reverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0, i, temp;
 
    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
  
    return reverse_num;
}

int main()
{
    unsigned int x = 2; 
    printf("%u", reverseBits(x));
}
