/*
Find the smallest positive number missing from an unsorted array | Set 1
You are given an unsorted array with both positive and negative elements.
 You have to find the smallest positive number missing from the array in O(n) 
 time using constant extra space. You can modify the original array.

Examples

 Input:  {2, 3, 7, 6, 8, -1, -10, 15}
 Output: 1

 Input:  { 2, 3, -7, 6, 8, 1, -10, 15 }
 Output: 4

 Input: {1, 1, 0, -1, -2}
 Output: 2 


Algo:

We can also use hashing. We can build a hash table of all positive elements in the given array. 
Once the hash table is built. We can look in the hash table for all positive integers, starting from 1. 
As soon as we find a number which is not there in hash table,
 we return it. This approach may take O(n) time on average, but it requires O(n) extra space.
 */