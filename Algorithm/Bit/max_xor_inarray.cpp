/*Find the maximum subarray XOR in a given array
Given an array of integers. find the maximum XOR subarray value in given array. Expected time complexity O(n).

Examples:

Input: arr[] = {1, 2, 3, 4}
Output: 7
The subarray {3, 4} has maximum XOR value

Input: arr[] = {8, 1, 2, 12, 7, 6}
Output: 15
The subarray {1, 2, 12} has maximum XOR value

Input: arr[] = {4, 6}
Output: 6
The subarray {6} has maximum XOR value

*/

// A simple C++ program to find max subarray XOR
#include<bits/stdc++.h>
using namespace std;
 
int maxSubarrayXOR(int arr[], int n)
{
    int ans = INT_MIN;     // Initialize result
 
    // Pick starting points of subarrays
    for (int i=0; i<n; i++)
    {
        int curr_xor = 0; // to store xor of current subarray
 
        // Pick ending points of subarrays starting with i
        for (int j=i; j<n; j++)
        {
            curr_xor = curr_xor ^ arr[j];
            ans = max(ans, curr_xor);
        }
    }
    return ans;
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {8, 1, 2, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max subarray XOR is " << maxSubarrayXOR(arr, n);
    return 0;
}
/*Run on IDE
Output:

Max subarray XOR is 15
Time Complexity of above solution is O(n2).

An Efficient Solution can solve the above problem in O(n) time under the assumption that integers take 
fixed number of bits to store. The idea is to use Trie Data Structure. And that is out of course*/