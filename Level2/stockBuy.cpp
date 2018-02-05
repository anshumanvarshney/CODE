/*
Stock buy and sell
The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling
 in those days. 

Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:

(0 3) (4 6) 
(1 4) (5 9) 
Notice: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, output should be in a single line.
*/

#include<bits/stdc++.h>
using namespace std;

struct stock
{
    int buy;
    int sell;
};

int main()
{
    int n,p;
    cin>>p;
    while(p--)
    {
        int n;
        cin>>n;
        int a[n];
        int i;
        for(i=0;i<n;i++)
            cin>>a[i];
        stock ob[n/2 + 1];//note
        i=0;
        int count=0;
        while(i<n-1)
        {
            while(i<n-1&& a[i]>a[i+1]) i++;
            if(i==n-1)
                break;
            ob[count].buy=i;
            i++;    
            while(i<n&& a[i]>a[i-1]) i++;
            ob[count].sell=i-1; //note   
            count++;
        }
        if(count==0)//note
            cout<<"No Profit";
        for(i=0;i<count;i++)
        {
            cout<<"("<<ob[i].buy<<" "<<ob[i].sell<<") ";
        }
        cout<<"\n";
	    
    }
    return 0;
}