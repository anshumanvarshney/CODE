/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be
 performed by a single person, assuming that a person can only work on a single activity at a time.
 
 Note : The start time and end time of two activities may coincide.
 
 Example 1 : Consider the following 3 activities sorted by
by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities. The 
maximum set of activities that can be executed 
is {0, 2} [ These are indexes in start[] and 
finish[] ]

Example 2 : Consider the following 6 activities 
sorted by by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The 
maximum set of activities that can be executed 
is {0, 1, 3, 4} [ These are indexes in start[] and 
finish[] ]

*/
#include<bits/stdc++.h>
using namespace std;

struct activity
{
    int s;
    int f;
};

bool compare(activity i1,activity i2)
{
    return (i1.f<i2.f);
}



int main()
 {
	//welcome Anshuman Varshney
	activity ob[1000];
	int p;
	cin>>p;
	while(p--)
	{
	    int n,i;
	    cin>>n;
	    for(i=0;i<n;i++)
	        cin>>ob[i].s;
	    for(i=0;i<n;i++)
	        cin>>ob[i].f;
	    sort(ob,ob+n,compare); //sort according to finish time    
	    int count =1;//first activity always got executed
	    i=0;
	    for(int j=1;j<n;j++)
	    {
	        if(ob[j].s>=ob[i].f)
	        {
	            count++;//in place off count if the actual content they are asking in question then print accordingly 
	            i=j;//eg: ob[j].s or ob[j].f or actual activity like which one
	        }
	    }
	    cout<<count<<"\n";
	}
	return 0;
}