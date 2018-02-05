/*
Given an array of distinct integers and a sum value. Find count of triplets with sum smaller than given sum value.
 Expected Time Complexity is O(n2).

Examples:

Input : arr[] = {-2, 0, 1, 3}
        sum = 2.
Output : 2
Explanation :  Below are triplets with sum less than 2
               (-2, 0, 1) and (-2, 0, 3) 

Input : arr[] = {5, 1, 3, 4, 7}
        sum = 12.
Output : 4
Explanation :  Below are triplets with sum less than 4
               (1, 3, 4), (1, 3, 5), (1, 3, 7) and 
               (1, 4, 5)

*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
   int i,j,k,sum,c=0,n;
   int a[]={5, 1, 3, 4, 7};
   //don't sort the array it increases time complexity by log(n) because we get same result without sorting ...
   n=sizeof(a)/sizeof(int);
   sum=12;
   for(i=0;i<=n-3;i++)
   {
	   for(j=i+1;j<=n-2;j++)
	   {
		   for(k=j+1;k<=n-1;k++)
		   {
			   if((a[i]+a[j]+a[k])<sum)
			   {
				   c++;
			   }
		   }
	   }
   }
   cout<<c;
   
}
/*
Time complexity of above solution is O(n3). An Efficient Solution can count triplets in O(n2) by sorting the array first
*/

#include<bits/stdc++.h>
using namespace std;
 
int countTriplets(int arr[], int n, int sum)
{
    // Sort input array
    sort(arr, arr+n);
 
    // Initialize result
    int ans = 0;
 
    // Every iteration of loop counts triplet with
    // first element as arr[i].
    for (int i = 0; i < n - 2; i++)
    {
        // Initialize other two elements as corner elements
        // of subarray arr[j+1..k]
        int j = i + 1, k = n - 1;
 
        // Use Meet in the Middle concept
        while (j < k)//condition is neccessary
        {
            // If sum of current triplet is more or equal,
            // move right corner to look for smaller values
            if (arr[i] + arr[j] + arr[k] >= sum)//important line
                k--;
 
            // Else move left corner
            else
            {
                // This is important. For current i and j, there
                // can be total k-j third elements.
                ans += (k - j);
                j++;
            }
        }
    }
    return ans;
}
 
// Driver program
int main()
{
    int arr[] = {5, 1, 3, 4, 7};
    int n = sizeof arr / sizeof arr[0];
    int sum = 12;
    cout << countTriplets(arr, n, sum) << endl;
    return 0;
}