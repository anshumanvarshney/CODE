/*
Minimum XOR Value Pair
Given an array of integers. Find the pair in an array which has minimum XOR value.
Examples:

Input : arr[] =  {9, 5, 3}
Output : 6
        All pair with xor value (9 ^ 5) => 12, 
        (5 ^ 3) => 6 , (9 ^ 3) => 10.
        Minimum XOR value is 6

Input : arr[] = {1, 2, 3, 4, 5}
Output : 1 


A Simple Solution is generate all pairs of given array and compute XOR their values. 
Finally return minimum XOR value. This solution takes O(n2) time.

An Efficient solution can solve this problem in O(nlogn) time. Below is the algorithm:

1). Sort the given array
2). Traverse and check XOR for every consecutive pair
Below is C++ implementation of above approach:
*/
#include<bits/stdc++.h>
using namespace std;
 
// Function to find minimum XOR pair
int minXOR(int arr[], int n)
{   
    // Sort given array
    sort(arr, arr+n);
     
    int minXor = INT_MAX;
    int val = 0;
     
    // calculate min xor of consecutive pairs
    for(int i=0;i<n-1;i++)
    {
        val = arr[i]^arr[i+1];
        minXor = min(minXor, val);
    }
     
    return minXor;
}