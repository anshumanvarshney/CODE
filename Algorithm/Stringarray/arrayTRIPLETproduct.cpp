/*
Maximum product of a triplet (subsequnece of size 3) in array
Given an integer array, find a maximum product of a triplet in array.

Examples:

Input:  [10, 3, 5, 6, 20]
Output: 1200
Multiplication of 10, 6 and 20
 
Input:  [-10, -3, -5, -6, -20]
Output: -90

Input:  [1, -4, 3, -6, 7, 0]
Output: 168
*/


/*
Algorithm

Approach 1 (Naive, O(n3) time, O(1) Space)
A simple solution is to check for every triplet using three nested loops.

Approach 2: O(nlogn) Time, O(1) Space

Sort the array using some efficient in-place sorting algorithm in ascending order.
Return the maximum of product of last three elements of the array and product of first two elements and last element.(second one for negative elements eg:
    int arr[] = { -10, -3, 5, 6, -20 };
Approach 3: O(n) Time, O(1) Space

Scan the array and compute Maximum, second maximum and third maximum element present in the array.
Scan the array and compute Minimum and second minimum element present in the array.
Return the maximum of product of Maximum, second maximum and third maximum and product of Minimum, second minimum and Maximum element.	
*/
#include<bits/stdc++.h>
using namespace std;
/*
Algo 1:

int main()
{
int i,j,k,p[20],l=0,a[]={-10, -3, -5, -6, -20};
    for(i=0;i<=2;i++)
	{
		for(j=i+1;j<=3;j++)
		{
			for(k=j+1;k<=4;k++)
			{
				p[l++]=a[i]*a[j]*a[k];
			}
		}
	}
	int y=p[0];
	for(i=0;i<l-1;i++)
	{
		if(y<p[i])
			y=p[i];
	}
	cout<<y;
}
*/
/*

Algo 2:
int main()
{
	
	int i,j,n,a[]={-10, -3, -5, -6, -20};
	n=sizeof(a)/sizeof(int);
	sort(a,a+n);
	cout<<(max((a[n-1]*a[n-2]*a[n-3]),(a[0]*a[1]*a[n-1])));
}

Algo 3:
int maxProduct(int a[], int n)
{
    if (n < 3)
        return -1;
	int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;
	int minA = INT_MAX, minB = INT_MAX;
 
    for (int i = 0; i < n; i++)
    {
		if (maxA < a[i])
        {
            maxC = maxB;
            maxB = maxA;
            maxA = a[i];
        }
 
        else if (maxB < a[i])
        {
            maxC = maxB;
            maxB = a[i];
        }
 
     
        else if (maxC < a[i])
            maxC = a[i];
 
        if (minA > a[i])
        {
            minB = minA;
            minA = a[i];
        }
 
        else if(minB)
            minB = a[i];
    }
 
    return max(minA * minB * maxA,
               maxA * maxB * maxC);
}
 

int main()
{
    int a[] = { 1, -4, 3, -6, 7, 0 };
    int n = sizeof(a)/sizeof(int);
 
    int max = maxProduct(a,n);
 
    if (max == -1)
        cout << "No Triplet Exists";
    else
        cout << "Maximum product is " << max;
 
    return 0;
}

*/






















