/*
Given an array and a number k where k is smaller than size of array, 
we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.

Examples:

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 3
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 4
Output: 10

Algo mine (nlogn)

sort(a,a+n)
cout<<a[k-1];

Algo 2
Method 2 (Using Min Heap – HeapSelect)
We can find k’th smallest element in time complexity better than O(nLogn). 
A simple optomization is to create a Min Heap of the given n elements and call extractMin() k times.

Algo 3
or by using max_heap
*/

