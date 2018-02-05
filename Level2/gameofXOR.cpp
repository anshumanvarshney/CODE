/*
Game of XOR

You are given an array A[] of size N. Now, we call the value of an array the bit-wise XOR of all elements it contains.
 For example, the value of the array [1,2,3] = 1^2^3. Now, Your task is to find the bit-wise XOR
 of the values of all sub arrays of array A. 

Example:

Input: A[] = {1,2,3} 
Output: 2
xor[1] = 1, 
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result : 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
*/
// C++ program to get total xor of all subarray xors
#include <bits/stdc++.h>
using namespace std;

int getTotalXorOfSubarrayXors(int a[], int n)
{
	if(n%2==0) return 0;
     int i,j,rx=0;
    for(i=0;i<n;i+=2)
    {
        rx^=a[i];
    }
    return rx;
}
 
int main()
{
    int arr[] = {1,2,3,4};
    int N = sizeof(arr) / sizeof(arr[0]);
 
    cout << getTotalXorOfSubarrayXors(arr, N);
    return 0;
}