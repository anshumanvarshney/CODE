/**
basic question
**/

//path sum is equal to given sum
bool hasPathSum(struct node* node, int sum)
{
  /* return true if we run out of tree and sum==0 */
  if (node == NULL)
  {
     return (sum == 0);
  }
  
  else
  {
    bool ans = 0;  
  
    /* otherwise check both subtrees */
    int subSum = sum - node->data;
  
    /* If we reach a leaf node and sum becomes 0 then return true*/
    if ( subSum == 0 && node->left == NULL && node->right == NULL )
      return 1;
  
    if(node->left)
      ans = ans || hasPathSum(node->left, subSum);
    if(node->right)
      ans = ans || hasPathSum(node->right, subSum);
  
    return ans;
  }
}


//find two missing number
void findTwoMissingNumbers(int arr[], int n)
{
    /* Get the XOR of all elements in arr[] and
       {1, 2 .. n} */
    int XOR = arr[0];
    for (int i = 1; i < n-2; i++)
        XOR ^= arr[i];
    for (int i = 1; i <= n; i++)
        XOR ^= i;
 
    // Now XOR has XOR of two missing elements. Any set
    // bit in it must be set in one missing and unset in
    // other missing number
 
    // Get a set bit of XOR (We get the rightmost set bit)
    int set_bit_no = XOR & ~(XOR-1);
 
    // Now divide elements in two sets by comparing rightmost
    // set bit of XOR with bit at same position in each element.
    int x = 0, y = 0; // Initialize missing numbers
    for (int i = 0; i < n-2; i++)
    {
        if (arr[i] & set_bit_no)
            x = x ^ arr[i]; /*XOR of first set in arr[] */
        else
            y = y ^ arr[i]; /*XOR of second set in arr[] */
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & set_bit_no)
            x = x ^ i; /* XOR of first set in arr[] and
                         {1, 2, ...n }*/
        else
            y = y ^ i; /* XOR of second set in arr[] and
                         {1, 2, ...n } */
    }
 
    printf("Two Missing Numbers are\n %d %d", x, y);
}

//Below are steps.

Find XOR of all array elements and natural numbers from 1 to n. Let the array be arr[] = {1, 3, 5, 6}
   XOR = (1 ^ 3  ^ 5 ^ 6) ^ (1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6)
As per the property of XOR, same elements will cancel out and we will be left with 2 XOR 4 = 6 (110). But we don’t know the exact numbers,let them be X and Y.
A bit is set in xor only if corresponding bits in X and Y are different. This is the crucial step to understand.
We take a set bit in XOR. Let us consider the rightmost set bit in XOR, set_bit_no = 010
Now again if we XOR all the elements of arr[] and 1 to n that have rightmost bit set we will get one of the repeating numbers, say x.
Ex: Elements in arr[] with bit set: {3, 6}
Elements from 1 to n with bit set {2, 3, 6}
Result of XOR'ing all these is x = 2.
Similarly, if we XOR all the elements of arr[] and 1 to n that have rightmost bit not set, we will get the other element, say y.
Ex: Elements in arr[] with bit not set: {1, 5}
Elements from 1 to n with bit not set {1, 4, 5}
Result of XOR'ing all these is y = 4 

//find missing number in an array
#include<stdio.h>
 
/* getMissingNo takes array and size of array as arguments*/
int getMissingNo(int a[], int n)
{
    int i;
    int x1 = a[0]; /* For xor of all the elements in array */
    int x2 = 1; /* For xor of all the elements from 1 to n+1 */
     
    for (i = 1; i< n; i++)
        x1 = x1^a[i];
            
    for ( i = 2; i <= n+1; i++)
        x2 = x2^i;         
    
    return (x1^x2);
}
 
/*program to test above function */
int main()
{
    int a[] = {1, 2, 4, 5, 6};
    int miss = getMissingNo(a, 5);
    printf("%d", miss);
    getchar();
}

//check tree is BST or not without using extra space 
bool isBST(Node* root, Node* l=NULL, Node* r=NULL)
{
    // Base condition
    if (root == NULL)
        return true;
 
    // if left node exist that check it has
    // correct data or not
    if (l != NULL and root->data < l->data)
        return false;
 
    // if right node exist that check it has
    // correct data or not
    if (r != NULL and root->data > r->data)
        return false;
 
    // check recursively for every node.
    return isBST(root->left, l, root) and
           isBST(root->right, root, r);
}

int main()
{
	isBST(root);
}

//trailing zero in the factorial
int findTrailingZeros(int  n)
{
    // Initialize result
    int count = 0;
 
    // Keep dividing n by powers of 5 and update count
    for (int i=5; n/i>=1; i *= 5)
          count += n/i;
 
    return count;
}


//Majority Element
Given an array of size n, find the majority element.
 The majority element is the element that appears more than floor(n/2) times.
int Solution::majorityElement(const vector<int> &a) 
{
    int n=a.size();
    int i;
    map<int,int> m;
    for(i=0;i<n;i++)
    {
        m[a[i]]++;
    }
    for(auto j=m.begin();j!=m.end();j++)
    {
        if(j->second>=floor(n/2))
            return j->first;
    }
}


   //How to print maximum number of A’s using given four keys
This is a famous interview question asked in Google, Paytm and many other company interviews.
Below is the problem statement.

Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it
                 after what has already been printed
				 
Input:  N = 3
Output: 3
We can at most get 3 A's on screen by pressing 
following key sequence.
A, A, A

Input:  N = 7
Output: 9
We can at most get 9 A's on screen by pressing 
following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

Input:  N = 11
Output: 27
We can at most get 27 A's on screen by pressing 
following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V, Ctrl A, 
Ctrl C, Ctrl V, Ctrl V

The task is to find out the break=point after which we get the above suffix of keystrokes.
 Definition of a breakpoint is that instance after 
which we need to only press Ctrl-A, Ctrl-C once and the only Ctrl-V’s afterwards to generate the optimal length

int findoptimal(int N)
{
    // The optimal string length is N when N is smaller than 7
    if (N <= 6)
        return N;
 
    // Initialize result
    int max = 0;
 
    // TRY ALL POSSIBLE BREAK-POINTS
    // For any keystroke N, we need to loop from N-3 keystrokes
    // back to 1 keystroke to find a breakpoint 'b' after which we
    // will have Ctrl-A, Ctrl-C and then only Ctrl-V all the way.
    int b;
    for (b=N-3; b>=1; b--)
    {
            // If the breakpoint is s at b'th keystroke then
            // the optimal string would have length
            // (n-b-1)*screen[b-1];
            int curr = (N-b-1)*findoptimal(b);
            if (curr > max)
                max = curr;
     }
     return max;
}

   
//c) For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1
   
Algorithm 2 (Optimized):
Traverse the array once.
1: If the stack is empty or array[i] is less than stack.top, push the array[i] on the stack.
2: While array[i] is greater than stack.top, Pop top element & print 'Next Greater Element of top is array[i]'.
3: Push array[i] on the stack.
4: Repeat steps 2-3 till the end of array is reached.
5: Finally, print null as next greater element for all remaining stack elements.
Time Complexity: O(n)
Space Complexity: O(n)

For example:
Input array:  98, 23, 54, 12, 20, 7, 27
Output:
Next greater element for 23     = 54
Next greater element for 12     = 20
Next greater element for 7      = 27
Next greater element for 20     = 27
Next greater element for 27     = null
Next greater element for 54     = null
Next greater element for 98     = null

//Given an array of size n, find a peak element in the array.
For example: 
In Array [1,4,3,6,7,5] 4 and 7 are Peak Elements. Return any one Peak Element.
peak = greter than its neighbour

O(n) traverse
O(log n) binary search
We can use Divide and Conquer to find a peak in O(Logn) time. The idea is Binary Search based,
 we compare middle element with its neighbors. 
If middle element is not smaller than any of its neighbors, then we return it.
 If the middle element is smaller than the its left neighbor, then there is 
 always a peak in left half (Why? take few examples). 
 If the middle element is smaller than the its right neighbor, then there is always a peak
 in right half (due to same reason as left half). Following are C and Java implementations of this approach.

// A C++ program to find a peak element element using divide and conquer
#include <stdio.h>
 
// A binary search based function that returns index of a peak element
int findPeakUtil(int arr[], int low, int high, int n)
{
    // Find index of middle element
    int mid = low + (high - low)/2;  /* (low + high)/2 */
 
    // Compare middle element with its neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
            (mid == n-1 || arr[mid+1] <= arr[mid]))
        return mid;
 
    // If middle element is not peak and its left neighbour is greater 
    // than it, then left half must have a peak element
    else if (mid > 0 && arr[mid-1] > arr[mid])
        return findPeakUtil(arr, low, (mid -1), n);
 
    // If middle element is not peak and its right neighbour is greater
    // than it, then right half must have a peak element
    else return findPeakUtil(arr, (mid + 1), high, n);
}
 
// A wrapper over recursive function findPeakUtil()
int findPeak(int arr[], int n)
{
    return findPeakUtil(arr, 0, n-1, n);
}
 
/* Driver program to check above functions */
int main()
{
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Index of a peak point is %d", findPeak(arr, n));
    return 0;
}   

//first non repeating charactor in a string
Example:
Input: ADBCGHIEFKJLADTVDERFSWVGHQWCNOPENSMSJWIERTFB

Output:
K
algo1:
using count array 
but if the string is not sorted then we have to check according to char by char

optimized
Algorithm2(Optimized):
Use index array for storing the index of the string elements.
1: Create an index array.
2: Initialize the index of all index array elements to -1.
3: Traverse the string once and for element of the string, check the value of index of that string element in index array.
a. If index is -1, it is the first occurrence in the string. Set index[string.charAt(i)] = i
b. Else, the element is repeating, set index[string.charAt(i)] = -2//indicate occur twice and a[i]=-2 for repeated
4: Traverse the index array once, find the minimum value in the array which is non negative. If found, 
this is the index of the first non repeating character in the string. 
Else, return null.

Time Complexity: O(n)
Space Complexity: O(1)

//Design a data structure that supports insert, delete, search and getRandom in constant time

insert(x)
1) Check if x is already present by doing a hash map lookup.
2) If not present, then insert it at the end of the array.
3) Add in hash table also, x is added as key and last array index as index.

remove(x)
1) Check if x is present by doing a hash map lookup.
2) If present, then find its index and remove it from hash map.
3) Swap the last element with this element in array and remove the last element.
Swapping is done because the last element can be removed in O(1) time.
4) Update index of last element in hash map.

getRandom()
1) Generate a random number from 0 to last index.
2) Return the array element at the randomly generated index.

search(x)
Do a lookup for x in hash map.

#include<bits/stdc++.h>
using namespace std;
 
// class to represent the required data structure
class myStructure
{
    // A resizable array
    vector <int> arr;
     
    // A hash where keys are array elements and vlaues are
    // indexes in arr[]
    map <int, int> Map;
 
    public:
    // A Theta(1) function to add an element to MyDS
    // data structure
    void add(int x)
    {
        // If ekement is already present, then noting to do
        if(Map.find(x) != Map.end())
            return;
             
        // Else put element at the end of arr[]
        int index = arr.size();
        arr.push_back(x);
             
        // and hashmap also
        Map.insert(std::pair<int,int>(x, index));
    }
         
    // function to remove a number to DS in O(1)
    void remove(int x)
    {
        // element not found then return
        if(Map.find(x) == Map.end())
            return;
             
        // remove element from map
        int index = Map.at(x);
        Map.erase(x);//delete the x element
             
        // swap with last element in arr
        // then remove element at back
        int last = arr.size() - 1;
        swap(arr[index], arr[last]);
        arr.pop_back();
             
        // Update hash table for new index of last element
        Map.at(arr[index]) = index;
    }
         
    // Returns index of element if element is present, otherwise null
    int search(int x)
    {
        if(Map.find(x) != Map.end())
        return Map.at(x);
        return -1;
    }
         
    // Returns a random element from myStructure
    int getRandom()
    {
        // Find a random index from 0 to size - 1
        srand (time(NULL));
        int random_index = rand() % arr.size();
             
         // Return element at randomly picked index
        return arr.at(random_index);
    }    
};
 
// Driver main
int main()
{
    myStructure ds;
    ds.add(10);
    ds.add(20);
    ds.add(30);
    ds.add(40);
    cout << ds.search(30) << endl;
    ds.remove(20);
    ds.add(50);
    cout << ds.search(50) << endl;
    cout << ds.getRandom() << endl;
}

//count frequency of array from 1 to n;
algo1: using count array but O(n) time and space
algo2: using index%n method and then divide index/n 
O(n) time with constant space


//1- delete mid element from ll
algo1:
using slow fast 
slow=slow->next->next;

or 
algo2:
temp=slow->next
using slow->data=slow->next->data;
slow->next=slow->next->next;
delete temp

//2- change the value of element to greater in right in ll
i/p = 6 5 2 3 1 
o/p = 5 3 3 1 -1
idea same as array 
first reverse the ll
then apply same logic by pointing greater from last

//3- Segregate even and odd nodes in a Linked List
Input: 17->15->8->12->10->5->4->1->7->6->NULL
Output: 8->12->10->4->6->17->15->5->1->7->NULL

Input: 8->12->10->5->4->1->6->NULL
Output: 8->12->10->4->6->5->1->NULL

take all the odd element into end 
and traverse againg and change the pointer if odd appears

//4 Given two integer arrays where second array is duplicate of first array with just 1 element missing. Find the element.
Example: 

Input:
Array1 - 9 7 8 5 4 6 2 3 1
Array2 - 2 4 3 9 1 8 5 6

Output:
7

algo1:
hashing the smaller array into map and use find function to find the no. that is not present
but O(n) time and space

algo2:
using xor or +/- 
int res=0;
iterate through both the array we get missing number
i.e for(i=0 to n) res^=a[i];
	for(i=0 to m) res^=b[i];
	cout<<res;
//using addition and subtraction	
 private static void findMissingNumberUsingSum(int[] array1, int[] array2) {
77	        int result = 0;
78	        for(int i = 0; i < array1.length; i++) {
79	            result += array1[i];
80	        }
81	        for(int i = 0; i < array2.length; i++) {
82	            result -= array2[i];
83	        }
84	        System.out.println("Missing element = "  + result);
85	    }

//using xor
34	    private static void findMissingNumber(int[] array1, int[] array2) {
35	        int result = array1[0];
36	        for (int i = 1; i < array1.length ; i++) {
37	            result = result ^ array1[i];
38	        }
39	        for (int i = 0; i < array2.length ; i++) {
40	            result = result ^ array2[i];
41	        }
42	        System.out.println("Missing element = "  + result);
43	    }
	
//5 Find smallest range containing elements from k lists
Given k sorted lists of integers of size n each, find the smallest range that includes at least
 element from each of the k lists. If more than one smallest ranges are found, print any one of them.

Example :

Input:
K = 3
arr1[] : [4, 7, 9, 12, 15]
arr2[] : [0, 8, 10, 14, 20]
arr3[] : [6, 12, 16, 30, 50]
Output:
The smallest range is [6 8] 
Explanation: Smallest range is formed by 
number 7 from first list, 8 from second
list and 6 from third list.

Algo:
first select first 3 element
then check the range and store in res;
move the pointer with small no. ahead
check the range 
and update res
do it until any one of the range get over
O(nk)


optimization:
we can use min heap to get the min at every step
i.e for every 3 value every time 
and then move the pointer ahead
O(nlogk)


//find a number which occurs odd number of times

Example:
Input: 2 3 4 3 1 4 5 1 4 2 5
Output: 4

Algorithm:
Initialize result = 0.
Iterate over the array and XOR result with each element of the input array.
Once iteration over the array is done, print result as the output.

Order of the Algorithm:
Time Complexity: O(n)
Space Complexity: O(1)



//leader in an array
leader in an array is the element which is larger than all the element to its right
i/p= 98 23 54 12 20 7 27
o/p= 27 54 98

algo:
start from rightmost element and then check for larger than current element 
same as question print greater to its right

//find missing number from 1 to n in less than O(n)
O(n) using n(n+1)/2-sum of element or iterating
xor method 
in last
     
//remove nth from end
ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    int c=0;
    for(ListNode* temp=head;temp!=NULL;temp=temp->next)c++;
    ListNode* temp;
    if(c<=n)
    {
        temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    ListNode* prev,*curr=head;
    int d=c-n;
    while(d--)
    {
        prev=curr;
        curr=curr->next;    
    }
    prev->next=curr->next;
    delete curr;
    return head;
}

//Given an unsorted array of integers, find the shortest subarray, which upon sorting will result in complete sorted array.
i/p: [1 4 7 3 10 48 17 26 30 45 50 62]
find start index and end index i.e si=7, ei=17
find min and max between si and ei
now find 0 to si for which min < a[i] say x;
now find ei to n-1 for which max >a[i] say y;
now from x to y we have subarray so sort the subarray

Algorithm:
1: From the beginning of the array, move to element in the array up to which the elements are sorted i.e. 
	where array[i] is greater than array[i+1]. Set startIndex = i.
2: From the end of the array, move to the element up to which the elements are sorted in reverse order i.e. 
	where array[j-1] is greater than array[j]. Set endIndex = j.
3: Find the minimum and maximum elements in the subarray from startIndex to endIndex.
4: Search the sorted array from 0 to startIndex to find the index at which minimum element will be in sorted array 
	say, minIndex.
5: Search the sorted array from endIndex to end of array to find the index at which maximum element will be in 
	sorted array say, maxIndex.
6: Resultant sub array is the subarray between minIndex to maxIndex.

	 
//Given a matrix of dimensions mxn having all entries as 1 or 0, find out the size of maximum size square 
//sub-matrix with all 1s. 
				  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};	 
				   
				   o/p:
				      0  1  1  0  1
					  1  1  0  1  0
					  0  1  1  1  0
				      1  1  2  2  0
					  1  2  2  3  1
					  0  0  0  0  0
					  
					  a[4][3] =3 indicate the 3*3 matrix and it is bottom right element

dp approach
1) Construct a sum matrix S[R][C] for the given M[R][C].
     a)	Copy first row and first columns as it is from M[][] to S[][]
     b)	For other entries, use following expressions to construct S[][]
         If M[i][j] is 1 then
            S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
         Else /*If M[i][j] is 0*/
            S[i][j] = 0
2) Find the maximum entry in S[R][C]
3) Using the value and coordinates of maximum entry in S[i], print 
   sub-matrix of M[][]
void printMaxSubSquare(bool M[R][C])
{
  int i,j;
  int S[R][C];
  int max_of_s, max_i, max_j; 
  
  /* Set first column of S[][]*/
  for(i = 0; i < R; i++)
     S[i][0] = M[i][0];
  
  /* Set first row of S[][]*/    
  for(j = 0; j < C; j++)
     S[0][j] = M[0][j];
      
  /* Construct other entries of S[][]*/
  for(i = 1; i < R; i++)
  {
    for(j = 1; j < C; j++)
    {
      if(M[i][j] == 1) 
        S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
      else
        S[i][j] = 0;
    }    
  } 
   
  /* Find the maximum entry, and indexes of maximum entry 
     in S[][] */
  max_of_s = S[0][0]; max_i = 0; max_j = 0;
  for(i = 0; i < R; i++)
  {
    for(j = 0; j < C; j++)
    {
      if(max_of_s < S[i][j])
      {
         max_of_s = S[i][j];
         max_i = i; 
         max_j = j;
      }        
    }                 
  }     
   
  printf("Maximum size sub-matrix is: \n");
  for(i = max_i; i > max_i - max_of_s; i--)
  {
    for(j = max_j; j > max_j - max_of_s; j--)
    {
      printf("%d ", M[i][j]);
    }  
    printf("\n");
  }  
}     


//Given two strings 'pattern' and 'text', find whether any anagram of string pattern is a substring of text.

Example:
Input:
text = ideserve
pattern = veer
Output:
true
Substring which is an anagram of pattern: erve (ideserve)
ALgo:1 using hashing i.e take 4 char and check one by one i.e in map no. of frequence as well as char 
if(not) then increment and check again (while incrementing put the start count =0 in map<char,int> i.e integer part)
if yiu reach end then not found

//Longest Substring With M Unique Characters
i.e i/p karappa
o/p : i/p: if(m=2) o/p: appa
	  i/p: if(m=3) o/p: arappa
using previous method i.e increment and check in hash if violates then put 0 in value and increment end
use two start and end pointer and check 
length=end-start

//(Longest Common Substring)
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

Examples :

Input : X = "GeeksforGeeks", y = "GeeksQuiz"
Output : 5
The longest common substring is "Geeks" and is of
length 5.

Input : X = "abcdxyz", y = "xyzabcd"
Output : 4

int LCSubStr(char *X, char *Y, int m, int n)
{
    // Create a table to store lengths of longest common suffixes of
    // substrings.   Notethat LCSuff[i][j] contains length of longest
    // common suffix of X[0..i-1] and Y[0..j-1]. The first row and
    // first column entries have no logical meaning, they are used only
    // for simplicity of program
    int LCSuff[m+1][n+1];
    int result = 0;  // To store length of the longest common substring
 
    /* Following steps build LCSuff[m+1][n+1] in bottom up fashion. */
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else LCSuff[i][j] = 0;
        }
    }
    return result;
}


//Remove Duplicates from Sorted Array using constant space
int Solution::removeDuplicates(vector<int> &a) {
    int n=a.size();
    if(n==0||n==1)
        return n;
    int j=0;    
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])
            a[j++]=a[i];    
    }
    a[j++]=a[n-1];
    return j;
}

//Given three sorted arrays A, B and Cof not necessarily same sizes.
Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c 
such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]

int Solution::solve(vector<int> &a, vector<int> &b, vector<int> &c) 
{
    int i=0,j=0,k=0,res=INT_MAX;
    int x=a.size(),y=b.size(),z=c.size();
    while(i<x&&j<y&&k<z)
    {
        int p=min(a[i],min(b[j],c[k]));
        int q=max(a[i],max(b[j],c[k]));
        res=min(res,q-p);
        if(p==a[i]) i++;
        else if(p==b[j]) j++;
        else if(p==c[k]) k++;
    }
    return res;
}


//1 1 2 2 3 =1 2 3
int removeDuplicates(vector<int> &A) {
			int count = 0, n = A.size();
			for (int i = 0; i < n; i++) { 
				if (i < n - 1 && A[i] == A[i+1]) continue;
				else {
					A[count] = A[i];
					count++;
				}
			}
			return count;
		}  
		
//allow 2
int Solution::removeDuplicates(vector<int> &a) {

    int t=a[0],k=1,c=0;
 
    for(int i=1;i<a.size();i++)
    {
        if(t==a[i])
        {
            c++;
            if(c<2)
                a[k++]=a[i];
                
        }
        else 
        {
            c=0;
            t=a[i];
            a[k++]=t;
        }
    }
    
    return k;
}		
		
		
//Remove Element

Given an array and a value, remove all the instances of that value in the array. 
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.

 Example:
If array A is [4, 1, 1, 2, 1, 3]
and value element is 1, 
then new length is 3, and A is now [4, 2, 3] 		


int Solution::removeElement(vector<int> &a, int x) {

    int k=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=x)
            a[k++]=a[i];
    }
    return k;
}

