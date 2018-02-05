/*
Minimum Number of Platforms Required for a Railway/Bus Station
Given arrival and departure times of all trains that reach a railway station, 
find the minimum number of platforms required for the railway station so that no train waits.
We are given two arrays which represent arrival and departure times of trains that stop

Examples:

Input:  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
        dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
There are at-most three trains at a time (time between 11:00 to 11:20)

	arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
   dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

All events sorted by time.
Total platforms at any time can be obtained by subtracting total 
departures from total arrivals by that time.
 Time     Event Type     Total Platforms Needed at this Time                               
 9:00       Arrival                  1
 9:10       Departure                0
 9:40       Arrival                  1
 9:50       Arrival                  2
 11:00      Arrival                  3 
 11:20      Departure                2
 11:30      Departure                1
 12:00      Departure                0
 15:00      Arrival                  1
 18:00      Arrival                  2 
 19:00      Departure                1
 20:00      Departure                0

Minimum Platforms needed on railway station = Maximum platforms 
                                              needed at any time 
                                           = 3  
*/


/*
different from activity problem

Input:
6
900 930 1100 1135 1500 1800
920 935 1102 1140 1520 1815

Its Correct output is:
1(according to min platform)

And Your Output is:
6(according to activity problem)


*/


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//welcome Anshuman Varshney
	int p;
	cin>>p;
	while(p--)
	{
	    int n,a[5000],b[5000],i,j,res,count;
	    cin>>n;
	    for(i=0;i<n;i++)
	        cin>>a[i];
	    for(i=0;i<n;i++)
	        cin>>b[i];     
	   
	    sort(a,a+n);
	    sort(b,b+n);
	    i=1;//arrival time should be less than departure
	    j=0;
	    res=1;
	    count=1;
	    while(i<n&&j<n)
	    {
	        if(a[i]<b[j])
	        {
	            count++;
	            i++;
	            if(res<count)
	                res=count;
	        }
	        else
	        {
	            count--;
	            j++;
	        }
	    }
	    cout<<res<<"\n";
	    
	}
	return 0;
}