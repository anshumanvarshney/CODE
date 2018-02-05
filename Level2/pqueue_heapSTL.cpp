/*
Priority Queue in C++ Standard Template Library (STL)
Priority queues are a type of container adaptors, specifically designed such that the first element 
of the queue is the greatest of all elements in the queue.
 
The functions associated with priority queue are:
empty() – Returns whether the queue is empty
size() – Returns the size of the queue
top() – Returns a reference to the top most element of the queue
push(g) – Adds the element ‘g’ at the end of the queue
pop() – Deletes the first element of the queue
*/
#include <iostream>
#include <queue>
 
using namespace std;
 
void showpq(priority_queue <int> gq)
{
    priority_queue <int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
 
int main ()
{
    priority_queue <int> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);
 
    cout << "The priority queue gquiz is : ";
    showpq(gquiz);
 
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();
 
 
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showpq(gquiz);
 
    return 0;
}
/*
Run on IDE
 
The output of the above programs is :

The priority queue gquiz is : 	30	20	10	5	1

gquiz.size() : 5
gquiz.top() : 30
gquiz.pop() : 	20	10	5	1
*/

//How to implement Min Heap using STL?
In C++ STL, there is priority_queue that can directly be used to implement Max Heap. See below example.

// C++ program to show that priority_queue is by
// default a Max Heap
#include <bits/stdc++.h>
using namespace std;
 
// Driver code
int main ()
{
    // Creates a max heap
    priority_queue <int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);
 
    // One by one extract items from max heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
 
    return 0;
}
/*
Run on IDE
Output :

30 20 10 5 1
Since elements are printed in descending order, we have a max heap by default.
*/
 

//How to implement Min Heap?
priority_queue supports a constructor that requires two extra arguments to make it min heap.

    //priority_queue <Type, vector<Type>, ComparisonType > min_heap;
`

Below is an example for integers.

// C++ program to us priority_queue to implement min heap
#include <bits/stdc++.h>
using namespace std;
 
// Driver code
int main ()
{
    // Creates a max heap
    priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);
 
    // One by one extract items from max heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
 
    return 0;
}
/*
Run on IDE
Output :

1 5 10 20 30 
 */
 
 
//Heap using STL C++

Heap data structure can be implemented in a range using STL which allows faster input into heap 
and retrieval of a number always results in the largest number i.e. largest number of the remaining numbers 
is popped out each time. Other numbers of the heap are arranged depending upon the implementation.

Operations on heap :

1. make_heap() :- This function is used to convert a range in a container to a heap.
2. front() :- This function displays the first element of heap which is the maximum number.

// C++ code to demonstrate the working of 
// make_heap(), front()
#include<iostream>
#include<algorithm> // for heap operations
using namespace std;
int main()
{
     
    // Initializing a vector
    vector<int> v1 = {20, 30, 40, 25, 15};
     
    // Converting vector into a heap
    // using make_heap()
    make_heap(v1.begin(), v1.end());
     
    // Displaying the maximum element of heap
    // using front()
    cout << "The maximum element of heap is : ";
    cout << v1.front() << endl;
     
    return 0;
}
/*
Run on IDE
Output:

The maximum element of heap is : 40
 */

3. push_heap() :- This function is used to insert elements into heap. The size of the heap is increased by 1.
					New element is placed appropriately in the heap.

4. pop_heap() :- This function is used to delete the maximum element of the heap. The size of heap is decreased by 1.
				The heap elements are reorganised accordingly after this operation.

// C++ code to demonstrate the working of 
// push_heap() and pop_heap()
#include<iostream>
#include<algorithm> // for heap operations
using namespace std;
int main()
{
     
    // Initializing a vector
    vector<int> v1 = {20, 30, 40, 25, 15};
     
    // Converting vector into a heap
    // using make_heap()
    make_heap(v1.begin(), v1.end());
     
    // Displaying the maximum element of heap
    // using front()
    cout << "The maximum element of heap is : ";
    cout << v1.front() << endl;
     
    // using push_back() to enter element
    // in vector
    v1.push_back(50);
     
    // using push_heap() to reorder elements
    push_heap(v1.begin(), v1.end());
     
    // Displaying the maximum element of heap
    // using front()
    cout << "The maximum element of heap after push is : ";
    cout << v1.front() << endl;
     
     // using pop_heap() to delete maximum element
    pop_heap(v1.begin(), v1.end());
     
    // Displaying the maximum element of heap
    // using front()
    cout << "The maximum element of heap after pop is : ";
    cout << v1.front() << endl;
     
    return 0;
}
/*
Run on IDE
Output:

The maximum element of heap is : 40
The maximum element of heap after push is : 50
The maximum element of heap after pop is : 40
*/

5. sort_heap() :- This function is used to sort the heap. After this operation, the container is no longer a heap.

// C++ code to demonstrate the working of 
// sort_heap()
#include<iostream>
#include<algorithm> // for heap operations
using namespace std;
int main()
{
     
    // Initializing a vector
    vector<int> v1 = {20, 30, 40, 25, 15};
     
    // Converting vector into a heap
    // using make_heap()
    make_heap(v1.begin(), v1.end());
     
    // Displaying heap elements 
    cout << "The heap elements are : ";
    for (int &x : v1) 
       cout << x << " ";
    cout << endl;
     
    // sorting heap using sort_heap()
    sort_heap(v1.begin(), v1.end());
     
     // Displaying heap elements 
    cout << "The heap elements after sorting are : ";
    for (int &x : v1) 
       cout << x << " ";
     
    return 0;
}
/*
Run on IDE
Output:

The heap elements are : 40 30 20 25 15 
The heap elements after sorting are : 15 20 25 30 40 
*/

6. is_heap() :- This function is used to check whether the container is heap or not. 
			Generally, in most implementations, the reverse sorted container is considered as heap. 
			Returns true if container is heap else returns false.

6. is_heap_until() :- This function returns the iterator to the position till the container is the heap.
				Generally, in most implementations, the reverse sorted container is considered as heap.

// C++ code to demonstrate the working of 
// is_heap() and is_heap_until()
#include<iostream>
#include<algorithm> // for heap operations
using namespace std;
int main()
{
     
    // Initializing a vector
    vector<int> v1 = {40, 30, 25, 35, 15};
     
    // Declaring heap iterator
    vector<int>::iterator it1;
     
    // Checking if container is heap
    // using is_heap()
    is_heap(v1.begin(), v1.end())?
    cout << "The container is heap ":
    cout << "The container is not heap";
    cout << endl;
     
    // using is_heap_until() to check position 
    // till which container is heap
    auto it = is_heap_until(v1.begin(), v1.end());
   
    // Displaying heap range elements
    cout << "The heap elements in container are : ";
    for (it1=v1.begin(); it1!=it; it1++)
       cout << *it1 << " ";
    
    return 0;
}
Run on IDE
Output:

The container is not heap
The heap elements in container are : 40 30 25 
