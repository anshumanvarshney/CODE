/*
The task goes as follows : - He was given a string consisting of 1's and 0's.Now the task is to make 
the string consisting of only 1's.But he is allowed to perform only the following operation-
 Take exactly k consecutive elements of string and change 1 to 0 and 0 to 1 i.e apply not(!) operation on each element.

Each operation takes 1 sec so he has to tell the minimum
 time required to make the string of 1's only. If not possible print -1.Help Sachin in this task.\\
 SAMPLE INPUT 
3
00010110 3
11111 4
01010 4
SAMPLE OUTPUT 
3
0
-1
Explanation
In 1 testcase- You can get 1 by first changing the leftmost 3 elements, getting to 11110110, 
then the rightmost 3, getting to 11110001, and finally the 3 left out 0's to 11111111; In 3 sec.

In 2 testcase- String consist of only 1's so no change needed.

In 3 testcase- There is no way to make the string of only 1's so -1.
*/

ALGO:
Let us follow a greedy strategy. Let us start from the leftmost index of the string and iterate till the index 
((string length)-K).

Maintain an answer=0. Now if the curr index is 1 then just continue with the loop.
Else if the index is 0 then flip all the bits from the curr index up to the index curr index+ K.
Also update answer i.e answer++.

After this process if all elements of the array are 1 then print answer else print -1.