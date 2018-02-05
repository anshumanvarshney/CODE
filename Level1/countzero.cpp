/*
Count ‘d’ digit positive integers with 0 as a digit
Given a number d, representing the number of digits of a positive integer. Find the total count 
of positive integer (consisting of d digits exactly) which have at-least one zero in them.

Examples:

Input : d = 1
Output : 0
There's no natural number of 1 digit that
contains a zero.

Input : d = 2
Output : 9
The numbers are, 10, 20, 30, 40, 50, 60, 
                 70, 80 and 90.
				 
We can place any of {1, 2, ... 9} in D1
Hence D1 can be filled in 9 ways.

Apart from D1 all the other places can be  10 ways. 
(we can place 0 as well)
Hence the total numbers having d digits can be given as: 
Total =  9*10d-1

Now, let's find the numbers having d digits, that
don't contain zero at any place. 
In this case, all the places can be filled in 9 ways.
Hence count of such numbers is given by:
Non_Zero = 9d

Now the count of numbers having at least one zero 
can be obtained by subtracting Non_Zero from Total.
Hence Answer would be given by:
9*(10d-1 - 9d-1 )
*/

#include<bits/stdc++.h>
using namespace std;

int findCount(int d)
{
    return 9*(pow(10,d-1) - pow(9,d-1));
}

int main()
{
	int n;
	cin>>n;
	cout<<findCount(n);
}
/*
but if they ask like 
Given a number d, representing the number of digits of a number. Find the total count of positive integers
 which have at-least one zero in them and consist d or less digits.*/
#include<bits/stdc++.h>
using namespace std;

int findCount(int d)
{
    return 9*(pow(10,d-1) - pow(9,d-1));
}

int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		sum+=findCount(i);
	cout<<sum<<"\n";
}
 