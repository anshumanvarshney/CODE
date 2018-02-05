/*
Hashing concept
*/
uestion 3
Check if a given array contains duplicate elements within k distance from each other
Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array.
 Write a function that returns true if array contains duplicates within k distance.

Examples:

Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
Output: false
All duplicates are more than k distance away.

Input: k = 3, arr[] = {1, 2, 3, 1, 4, 5}
Output: true
1 is repeated at distance 3.

Input: k = 3, arr[] = {1, 2, 3, 4, 5}
Output: false

Input: k = 3, arr[] = {1, 2, 3, 4, 4}
Output: true
*/

Algorithm:
A Simple Solution is to run two loops. The outer loop picks every element ‘arr[i]’ as a starting element, 
the inner loop compares all elements which are within k distance of ‘arr[i]’. 
The time complexity of this solution is O(kn).

Efficient solution using hashing
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int k,n;
        bool status = false;
        cin >> k >> n;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(m.find(x) != m.end() && i - m[x] <= k){
                status = true;
            }
            m[x] = i;
        }
        if(status == true){
            cout <<"True\n";
        }else{
            cout <<"False\n";
        }
    }
	
	return 0;
}

/*
Question 1

Given two unsorted arrays, find all pairs whose sum is x
Given two unsorted arrays of distinct elements, the task is to find all pairs from both arrays whose sum is equal to x.

Examples:

Input :  arr1[] = {-1, -2, 4, -6, 5, 7}
         arr2[] = {6, 3, 4, 0}  
         x = 8
Output : 4 4
         5 3

Input : arr1[] = {1, 2, 4, 5, 7} 
        arr2[] = {5, 6, 3, 4, 8}  
        x = 9
Output : 1 8
         4 5
         5 4
*/

Algo:
run two loop check for every pair take O(n^2) time 
Time Complexity : O(n^2)
Auxiliary Space : O(1)


void findPairs(int arr1[], int arr2[], int n,
                               int m, int x)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (arr1[i] + arr2[j] == x)
                cout << arr1[i] << " "
                     << arr2[j] << endl;
}


Efficient Algo: using hashing
We store all first array elements in hash table. For elements of second array, we subtract every element
 from x and check the result in hash table. If result is present, we print the element and key in hash
 (which is an element of first array).

void findPairs(int arr1[], int arr2[], int n,
                               int m, int x)
{
    // Insert all elements of first array in a hash
    unordered_set<int> s;
    for (int i=0; i<n; i++)
        s.insert(arr1[i]);
 
    // Subtract sum from second array elements one
    // by one and check it's present in array first
    // or not
    for (int j=0; j<m; j++)
        if (s.find(x - arr2[j]) != s.end())
            cout << x-arr2[j] << " "
                 << arr2[j] << endl;
}
Time Complexity : O(n)
Auxiliary Space : O(n)


//In both above listed cases
Output:

6 2
4 4
6 2
7 1


/*
Question 2:
Given an array A[] and a number x, check for pair in A[] with sum as x
*/
METHOD 1 (Use Sorting)

Algorithm:

hasArrayTwoCandidates (A[], ar_size, sum)
1) Sort the array in non-decreasing order.
2) Initialize two index variables to find the candidate 
   elements in the sorted array.
       (a) Initialize first to the leftmost index: l = 0
       (b) Initialize second  the rightmost index:  r = ar_size-1
3) Loop while l < r.
       (a) If (A[l] + A[r] == sum)  then return 1
       (b) Else if( A[l] + A[r] <  sum )  then l++
       (c) Else r--    
4) No candidates in whole array - return 0

bool hasArrayTwoCandidates(int A[], int arr_size, int sum)
{
    int l, r;
 
    /* Sort the elements */
    quickSort(A, 0, arr_size-1);
 
    /* Now look for the two candidates in the sorted 
       array*/
    l = 0;
    r = arr_size-1; 
    while (l < r)
    {
         if(A[l] + A[r] == sum)
              return 1; 
         else if(A[l] + A[r] < sum)
              l++;
         else // A[i] + A[j] > sum
              r--;
    }    
    return 0;

Time Complexity: Depends on what sorting algorithm we use. If we use Merge Sort or Heap Sort then (-)(nlogn) in worst case.
 If we use Quick Sort then O(n^2) in worst case.
Auxiliary Space : Again, depends on sorting algorithm. For example auxiliary space is O(n) 
for merge sort and O(1) for Heap Sort.


Efficient Method
METHOD 2 (Use Hash Map)
Let sum be the given sum and A[] be the array in which we need to find pair.

1) Initialize Binary Hash Map M[] = {0, 0, ...}
2) Do following for each element A[i] in A[]
   (a)	If M[x - A[i]] is set then print the pair (A[i], x - A[i])
   (b)	Set M[A[i]]

void printPairs(int arr[], int arr_size, int sum)
{
  int i, temp;
  bool binMap[MAX] = {0}; /*initialize hash map as 0*/
 
  for (i = 0; i < arr_size; i++)
  {
      temp = sum - arr[i];
      if (temp >= 0 && binMap[temp] == 1)
         printf("Pair with given sum %d is (%d, %d) n", 
                 sum, arr[i], temp);
      binMap[arr[i]] = 1;
  }
}

/*
let input arr={1,4,45,6,10,8}
so

hash table ={1 4 45 6 }now 16-10=6 and  6 is present so found and print
*/

/*
Question 4
Find whether an array is subset of another array

Examples:
Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3}
Output: arr2[] is not a subset of arr1[]

Method 1 (Simple)
Use two loops: The outer loop picks all the elements of arr2[] one by one.
 The inner loop linearly searches for the element picked by outer loop.
 If all elements are found then return 1, else return 0.

 Method 2 (Use Sorting and Binary Search)

1) Sort arr1[] O(mLogm)
2) For each element of arr2[], do binary search for it in sorted arr1[].
         a) If the element is not found then return 0.
3) If all elements are present then return 1.
 */

Method 4 (Use Hashing)
1) Create a Hash Table for all the elements of arr1[].
2) Traverse arr2[] and search for each element of arr2[] in the Hash Table. If element is not found then return 0.
3) If all elements are found then return 1.

//using map
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//welcome Anshuman Varshney
	int p;
	cin>>p;
	while(p--)
	{
	    int n,m,i,j,a[100000],b[100000];
	    cin>>n>>m;
	    for(i=0;i<n;i++)
	        cin>>a[i];
	    for(i=0;i<m;i++)
	        cin>>b[i];
	    unordered_map<int,int> ma;
	    for(i=0;i<n;i++)
	        ma[a[i]]=1;
	    int flag=1;     
	    for(i=0;i<m;i++)
	    {
	        if((ma.find(b[i])!=ma.end())==false)//or if((ma.find(b[i])==ma.end())
	            flag=0;
	    }
	    if(flag==1)
	        cout<<"Yes";
	    else cout<<"No";
	    cout<<"\n";
	    
	}
	return 0;
}

//using set
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//welcome Anshuman Varshney
	int p;
	cin>>p;
	while(p--)
	{
	    int n,m,i,j,a[100000],b[100000];
	    cin>>n>>m;
	    for(i=0;i<n;i++)
	        cin>>a[i];
	    for(i=0;i<m;i++)
	        cin>>b[i];
	    unordered_set<int> ma;
	    for(i=0;i<n;i++)
	        ma.insert(a[i]);
	    int flag=1;     
	    for(i=0;i<m;i++)
	    {
	        if((ma.find(b[i])!=ma.end())==false)//or if((ma.find(b[i])==ma.end())
	            flag=0;
	    }
	    if(flag==1)
	        cout<<"Yes";
	    else cout<<"No";
	    cout<<"\n";
	    
	}
	return 0;
}


//unorderd_set in STL and its applications
unordered_set is implemented using hash table where keys are hashed into indices of this hash table so
 it is not possible to maintain an order. All operation on unordered_set takes constant time O(1) on an average
 which can go up to linear time in worst case which depends on the internally used hash function but practically 
 they perform very well and generally provide constant time lookup operation.
The unordered-set can contain key of any type – predefined or user-defined data structure but when we define key
 of type user define type, we need to specify our comparison function according to which keys will be compared.

set vs undered_set

Set set is an ordered sequence of unique keys whereas unordered_set is a set in which key can be stored in 
any order, so unordered.
Set is implemented as balanced tree structure that is why it is possible to maintain an order between 
the elements (by specific tree traversal). Time complexity of set operations is O(Log n) while for unordered_set, it is O(1).

Methods on unordered_set
For unordered_set many function are defined among which most useful are size and empty for capacity, 
find for searching a key, insert and erase for modification.
The Unordered_set allows only unique keys, for duplicate keys unordered_multiset should be used.

Example of declaration, find, insert and iteration in unordered_set is given below :

// C++ program to demonstrate various function of unordered_set
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    // declaring set for storing string data-type
    unordered_set<string> stringSet;
 
    // inserting various string, same string will be stored
    // once in set
    stringSet.insert("code");
    stringSet.insert("in");
    stringSet.insert("c++");
    stringSet.insert("is");
    stringSet.insert("fast");
 
    string key = "slow";
 
    //  find returns end iterator if key is not found,
    //  else it returns iterator to that key
    if (stringSet.find(key) == stringSet.end())
        cout << key << " not found\n\n";
    else
        cout << "Found " << key << endl << endl;
 
    key = "c++";
    if (stringSet.find(key) == stringSet.end())
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;
 
    // now iterating over whole set and printing its
    // content
    cout << "\nAll elements : ";
    unordered_set<string> :: iterator itr;
    for (itr = stringSet.begin(); itr != stringSet.end(); itr++)
        cout << (*itr) << endl;
}
Run on IDE
Output :

slow not found

Found c++

All elements : 
is
fast
c++
in
code
Find, insert and erase take constant amount of time on average. The find() function returns an iterator 
to end() if key is not there in set otherwise iterator to key position is returned. 
The iterator works as pointer to key values so we can get key by dereferencing them by *.

A practical problem based on unordered_set – given a set of integer number, find duplicate among them.

Input  : arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5}
Output : Duplicate item are : 5 2 1 
Below is C++ solution using unordered_set.

// C++ program to find duplicate from an array using
// unordered_set
#include <bits/stdc++.h>
using namespace std;
 
// Print duplicates in arr[0..n-1] using unordered_set
void printDuplicates(int arr[], int n)
{
    // declaring unordered sets for checking and storing
    // duplicates
    unordered_set<int> intSet;
    unordered_set<int> duplicate;
 
    // looping through array elements
    for (int i = 0; i < n; i++)
    {
        // if element is not there then insert that
        if (intSet.find(arr[i]) == intSet.end())
            intSet.insert(arr[i]);
 
        // if element is already there then insert into
        // duplicate set
        else
            duplicate.insert(arr[i]);
    }
 
    // printing the result
    cout << "Duplicate item are : ";
    unordered_set<int> :: iterator itr;
 
    // iterator itr loops from begin() till end()
    for (itr = duplicate.begin(); itr != duplicate.end(); itr++)
        cout << *itr << " ";
}
 
// Driver code
int main()
{
    int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
    int n = sizeof(arr) / sizeof(int);
 
    printDuplicates(arr, n);
    return 0;
}
Run on IDE
Output :

Duplicate item are : 5 2 1 


//unordered_map in STL and its applications
unordered_map is an associated container that stores elements formed by combination of key value and a mapped value.
 The key value is used to uniquely identify the element and mapped value is the content associated with the key. 
 Both key and value can be of any type predefined or user-defined.
Internally unordered_map is implemented using Hash Table, the key provided to map are hashed into indices of 
hash table that is why performance of data structure depends on hash function a lot but on an average
 the cost of look-up from hash table is O(1). In worst case unordered_map may require O(n) time but practically 
 it is much faster and outperforms tree based maps.

unordered_map vs unordered_set : 
In unordered_set, we have only key, no value, these are mainly used to see presence/absence in a set.
 For example, consider the problem of counting frequencies of individual words. We can’t use unordered_set 
 (or set) as we can’t store counts.

unordered_map vs map : 
map (like set) is an ordered sequence of unique keys whereas in unordered_map key can be stored in any order, so unordered.
Map is implemented as balanced tree structure that is why it is possible to maintain an order between 
the elements (by specific tree traversal). Time complexity of map operations is O(Log n) while for unordered_set,
 it is O(1) on average.

Methods on unordered_set
A lot of function are available which work on unordered_map. most useful of them are – operator =, operator [],
 empty and size for capacity, begin and end for iterator, find and count for lookup, insert and erase for modification.
The C++11 library also provides function to see internally used bucket count, bucket size and also used 
hash function and various hash policies but they are less useful in real application.
We can iterate over all elements of unordered_map using Iterator. Initialization, indexing and iteration 
is shown in below sample code :

// C++ program to demonstrate functionality of unordered_map
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    // Declaring umap to be of <string, double> type
    // key will be of string type and mapped value will
    // be of double type
    unordered_map<string, double> umap;
 
    // inserting values by using [] operator
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;
 
    // inserting value by insert function
    umap.insert(make_pair("e", 2.718));
 
    string key = "PI";
 
    // If key not found in map iterator to end is returned
    if (umap.find(key) == umap.end())
        cout << key << " not found\n\n";
 
    // If key found then iterator to that key is returned
    else
        cout << "Found " << key << "\n\n";
 
    key = "lambda";
    if (umap.find(key) == umap.end())
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;
 
    //  iterating over all value of umap
    unordered_map<string, double>:: iterator itr;
    cout << "\nAll Elements : \n";
    for (itr = umap.begin(); itr != umap.end(); itr++)
    {
        // itr works as a pointer to pair<string, double>
        // type itr->first stores the key part  and
        // itr->second stroes the value part
        cout << itr->first << "  " << itr->second << endl;
     }
}
Run on IDE
Output :

Found PI

lambda not found

All Elements : 
loge 1
log10 2.302
root3 1.732
e 2.718
root2 1.414
PI 3.14


A practical problem based on unordered_map – given a string of words, find frequencies of individual words.

Input :  str = "geeks for geeks geeks quiz practice qa for";
Output : Frequencies of individual words are
   (practice, 1)
   (for, 2)
   (qa, 1)
   (quiz, 1)
   (geeks, 3)
Below is C++ solution using unordered_set.

// C++ program to find freq of every word using
// unordered_map
#include <bits/stdc++.h>
using namespace std;
 
// Prints frequencies of individual words in str
void printFrequencies(const string &str)
{
    // declaring map of <string, int> type, each word
    // is mapped to its frequency
    unordered_map<string, int> wordFreq;
 
    // breaking input into word using string stream
    stringstream ss(str);  // Used for breaking words
    string word; // To store individual words
    while (ss >> word)
        wordFreq[word]++;
 
    // now iterating over word, freq pair and printing
    // them in <, > format
    unordered_map<string, int>:: iterator p;
    for (p = wordFreq.begin(); p != wordFreq.end(); p++)
        cout << "(" << p->first << ", " << p->second << ")\n";
}
 
// Driver code
int main()
{
    string str = "geeks for geeks geeks quiz "
                 "practice qa for";
    printFrequencies(str);
    return 0;
}
Run on IDE
Output :

(practice, 1)
(for, 2)
(qa, 1)
(quiz, 1)
(geeks, 3)