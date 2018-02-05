/*
O(n) time O(1) space
Find the element that appears once
Given an array where every element occurs three times, except one element which occurs only once.
 Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
 
Examples:

Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
Output: 2

We can use sorting to do it in O(nLogn) time. We can also use hashing, but the worst case 
time complexity of but hashing requires extra space.

The idea is to use bitwise operators for a solution that is O(n) time and uses O(1) extra space.
 The solution is not easy like other XOR based solutions, because all elements appear odd number of times here.
 The idea is taken from here.

Algo:
int getUniqueElement(int[] arr)
{
    int ones = 0 ; //At any point of time, this variable holds XOR of all the elements which have appeared "only" once.
    int twos = 0 ; //At any point of time, this variable holds XOR of all the elements which have appeared "only" twice.
    int not_threes ;

    for( int x : arr )//x=a[i]
    {
        twos |= ones & x ; //add it to twos if it exists in ones
        ones ^= x ; //if it exists in ones, remove it, otherwise, add it

        // Next 3 lines of code just converts the common 1's between "ones" and "twos" to zero.

        not_threes = ~(ones & twos) ;//if x is in ones and twos, dont add it to Threes.
        ones &= not_threes ;//remove x from ones
        twos &= not_threes ;//remove x from twos
    } 
    return ones;
} 
When finished, ones contains the bits that only appeared 3*n+1 times,
 which are the bits for the element that only appeared once. 
 
Explanation: 
 
Run a loop for all elements in array. At the end of every iteration, maintain following two values.

ones: The bits that have appeared 1st time or 4th time or 7th time .. etc.

twos: The bits that have appeared 2nd time or 5th time or 8th time .. etc.

Finally, we return the value of ‘ones’

How to maintain the values of ‘ones’ and ‘twos’?
‘ones’ and ‘twos’ are initialized as 0. For every new element in array,
 find out the common set bits in the new element and previous value of ‘ones’. 
 These common set bits are actually the bits that should be added to ‘twos’. 
 So do bitwise OR of the common set bits with ‘twos’. ‘twos’ also gets some extra bits that appear third time. 
These extra bits are removed later.
Update ‘ones’ by doing XOR of new element with previous value of ‘ones’. There may be some bits which appear 3rd time.
 These extra bits are also removed later.

Both ‘ones’ and ‘twos’ contain those extra bits which appear 3rd time. Remove these extra bits by finding out common
 set bits in ‘ones’ and ‘twos’.
 
ALgo mine

if space complexity is there then we use arr[ar[i]]++ concept and return position with 0 value
*/

#include<bits/stdc++.h>
using namespace std;

int getSingle(int arr[], int n)
{
    int ones = 0, twos = 0 ;
 
    int common_bit_mask;
 
    // Let us take the example of {3, 3, 2, 3} to understand this
    for( int i=0; i< n; i++ )
    {
        /* The expression "one & arr[i]" gives the bits that are
           there in both 'ones' and new element from arr[].  We
           add these bits to 'twos' using bitwise OR
 
           Value of 'twos' will be set as 0, 3, 3 and 1 after 1st,
           2nd, 3rd and 4th iterations respectively */
        twos  = twos | (ones & arr[i]);
 
 
        /* XOR the new bits with previous 'ones' to get all bits
           appearing odd number of times
 
           Value of 'ones' will be set as 3, 0, 2 and 3 after 1st,
           2nd, 3rd and 4th iterations respectively */
        ones  = ones ^ arr[i];//it gives only ones apperarance
 
 
        /* The common bits are those bits which appear third time
           So these bits should not be there in both 'ones' and 'twos'.
           common_bit_mask contains all these bits as 0, so that the bits can 
           be removed from 'ones' and 'twos'   
 
           Value of 'common_bit_mask' will be set as 00, 00, 01 and 10
           after 1st, 2nd, 3rd and 4th iterations respectively */
        common_bit_mask = ~(ones & twos);
 
 
        /* Remove common bits (the bits that appear third time) from 'ones'
             
           Value of 'ones' will be set as 3, 0, 0 and 2 after 1st,
           2nd, 3rd and 4th iterations respectively */
        ones &= common_bit_mask;
 
 
        /* Remove common bits (the bits that appear third time) from 'twos'
 
           Value of 'twos' will be set as 0, 3, 1 and 0 after 1st,
           2nd, 3rd and 4th itearations respectively */
        twos &= common_bit_mask;
 
        // uncomment this code to see intermediate values
        printf (" %d %d \n", ones, twos);
		/*
		once	twos
		3	 	0
		0 		3
		0 		1
		2 		0
		*/
    }
 
    return ones;
	//The element with single occurance is 2
}
 
int main()
{
    int arr[] = {3, 3, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The element with single occurrence is %d ",
            getSingle(arr, n));
    return 0;
}
 