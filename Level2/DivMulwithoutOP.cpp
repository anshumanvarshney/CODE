/*
Divide and multiple  two integers without using multiplication, division,mod operator,bitwise operators, and no loops

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.
*/

using bits concept

#include<bits/stdc++.h>
using namespace std;

int divide(int dd,int ds)
{
	dd=dd>>1;
	return dd;
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<divide(a,b);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
void multiply(int x, int y)
{
	int sign=1,i,sum=0;
	if(y<0)
	{
		sign=-1;
		y=y*sign;
	}
		for(i=0;i<y;i++)
		{
			sum+=x;
		}
		cout<<sign*sum;
}
 
int main()
{
 multiply(5,11);
  return 0;
}
