/*
Given an input stream of n integers the task is to insert integers to stream and print the median of 
the new stream formed by each insertion of x to the stream.

Example

Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)

Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4

Algorithm:

Create two heaps. One max heap to maintain elements of lower half and one min heap to maintain
 elements of higher half at any point of time..
Take initial value of median as 0.
For every newly read element, insert it into either max heap or min heap and calulate the median
 based on the following conditions:
If the size of max heap is greater than size of min heap and the element is less than previous median 
then pop the top element from max heap and insert into min heap and insert the new element to max heap 
else insert the new element to min heap. Calculate the new median as average of top of elements of both max and min heap.
If the size of max heap is less than size of min heap and the element is greater than previous median
 then pop the top element from min heap and insert into max heap and insert the new element to min heap
 else insert the new element to max heap. Calculate the new median as average of top of elements of both max and min heap.
If the size of both heaps are same. Then check if current is less than previous median or not. 
If the current element is less than previous median then insert it to max heap and new median will
 be equal to top element of max heap. If the current element is greater than previous median then 
 insert it to min heap and new median will be equal to top element of min heap.
Below is C++ implement
*/

#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//welcome Anshuman Varshney

	    int n,med=0,temp,j;
	    int a[100007],i,m;
	    cin>>n;
	    for(i=0;i<n;i++)
	        cin>>a[i];
	    for(i=0;i<n;i++)
	    {
	        temp=a[i];
	        j=i;
	        while(j>0&&temp<a[j-1])
	        {
	            a[j]=a[j-1];
	            j=j-1;
	        }
	        a[j]=temp;
	        m=(a[i/2]+a[(i+1)/2])/2;
	        cout<<m<<"\n";
	    }
	
	
	return 0;
}


//second method
 
 
priority_queue<int> mx;
 
priority_queue<int,vector<int>,greater<int> > mn;
 
void calculate_median(double x,double &median)
{
    /*  At any time we try to make heaps balanced and 
        their sizes differ by atmost 1. If heaps are 
        balanced,then we declare median as average of 
        min_heap_right.top() and max_heap_left.top()
        If heaps are unbalanced,then median is defined 
        as the top element of heap of larger size  */
      
    // case1(left side heap has more elements)
    if (mx.size() > mn.size())
    {
        if (x < median)
        {
            mn.push(mx.top());
            mx.pop();
            mx.push(x);
        }
        else
            mn.push(x);
 
        median = ((double)mx.top()
                +(double)mn.top())/2.0;
    }
 
    // case2(both heaps are balanced)
    else if (mx.size()==mn.size())
    {
        if (x < median)
        {
            mx.push(x);
            median = (double)mx.top();
        }
        else
        {
            mn.push(x);
            median = (double)mn.top();
        }
    }
 
    // case3(right side heap has more elements)
    else
    {
        if (x > median)
        {
            mx.push(mn.top());
            mn.pop();
            mn.push(x);
        }
        else
            mx.push(x);
 
        median = ((double)mx.top()
                 + (double)mn.top())/2.0;
    }
}
 
// Driver program to test above functions
int main()
{   
    // stream of integers
    double arr[] = {5, 15, 10, 20, 3};
    double median = 0;//stores the median 
     
    // size of stream
    int n = 5;
     
    // reading elements of stream one by one
    for (int i=0; i < n; i++)
    {   
        // calculating new median for each 
        // new element added to the stream
        calculate_median(arr[i], median);
        cout << setprecision(1) << fixed << median << "n";
    }
    return 0;
}
/*
Run on IDE
Output:

5.0
10.0
10.0
12.5
10.0
Time Complexity: O(n Log n)
Auxiliary Space : O(n)
*/