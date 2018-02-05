/*
Swap all odd and even bits
Given an unsigned integer, swap all odd bits with even bits. For example, 
if the given number is 23 (00010111), it should be converted to 43 (00101011). 
Every even position bit is swapped with adjacent bit on right side 
(even position bits are highlighted in binary representation of 23),
 and every odd position bit is swapped with adjacent on left side.
 
 My algo: without using bit
 convert no. into binary and then swap pairs

 Algo:
If we take a closer look at the example, we can observe that we basically need 
to right shift (>>) all even bits (In the above example, even bits of 23 are highlighted) by 1
 so that they become odd bits (highlighted in 43), and left shift (<<) all odd bits by 1
 so that they become even bits. The following solution is based on this observation. 
 The solution assumes that input number is stored using 32 bits.

Let the input number be x
1) Get all even bits of x by doing bitwise and of x with 0xAAAAAAAA.
 The number 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.eg 1 0 1 0
2) Get all odd bits of x by doing bitwise and of x with 0x55555555. 
The number 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0.eg 0 1 0 1
3) Right shift all even bits.
4) Left shift all odd bits.
5) Combine new even and odd bits and return.
*/

#include<bits/stdc++.h>
using namespace std;
 
unsigned int swapBits(unsigned int x)
{
    // Get all even bits of x
    unsigned int even_bits = x & 0xAAAAAAAA;//A=1010  we get 0 0 0 0 0 0 1 0
 
    // Get all odd bits of x
    unsigned int odd_bits  = x & 0x55555555; //5=0101 we get 0 0 0 1 0 1 0 1
 
    even_bits >>= 1;  // Right shift even bits// we get 0 0 0 0 0 0 0 1
    odd_bits <<= 1;   // Left shift odd bits// we get 0 0 1 0 1 0 1 0
 
    return (even_bits | odd_bits); // Combine even and odd bits we get 0 0 1 0 1 0 1 1
}
 
// Driver program to test above function
int main()
{
    unsigned int x = 23; // 00010111
 
    // Output is 43 (00101011)
    printf("%u ", swapBits(x));
 
    return 0;
}