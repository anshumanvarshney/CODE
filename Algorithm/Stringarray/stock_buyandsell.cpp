/*
Stock Buy Sell to Maximize Profit

The cost of a stock on each day is given in an array, 
find the max profit that you can make by buying and selling in those days.
For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, 
the maximum profit can earned by buying on day 0, selling on day 3. Again buy on day 4 and sell on day 6.
If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={100, 180, 260, 310, 40, 535, 695};
	int n=sizeof(a)/sizeof(int);
	int i=0,j;
	while(i<n)
	{
		int t=a[i];
		int y=t;
		for(j=i+1;j<n;j++)
		{
			if(y>a[j])
				break;
			else
				y=a[j];
		}
		if(i==0 && j-1==0)
		{
			cout<<"NO profit";
			break;
		}
		else
		cout<<"\nBuy on day :"<<i<<" Sell on day:"<<j-1;;
		i=j;
	}
	return 0;
}