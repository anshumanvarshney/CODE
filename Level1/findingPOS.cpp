/*
Finding Position

Some people are standing in a queue. A selection process follows a rule where people standing on even 
positions are selected. Of the selected people a queue is formed and again out of these only people on 
even position are selected.
 This continues until we are left with one person. Find out the position of that person in the original queue.
 
Input: n = 10
Output:8
Explanation : 
1 2 3 4 5 6 7 8 9 10  ===>Given queue
    2 4 6 8 10
       4 8
        8

Input: n = 17
Input: 16
Explanation : 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17  ===>Given queue
        2 4 6 8 10 12 14 16
            4 8 12 16
              8 16
               16
			   
basically the question is
Highest power of 2 less than or equal to given number	
Input : n = 10
Output : 8

Input : n = 19
Output : 16

Input : n = 32
Output : 32		   
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int x=log2(n);
	    int res=pow(2,x);
	    cout<<res<<"\n";
	}
	return 0;
}

/*
//or using bit

int highestPowerof2(int n)
{
    int res = 0;
    for (int i=n; i>=1; i--)
    {
        // If i is a power of 2
        if ((i & (i-1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}
*/