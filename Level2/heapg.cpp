#include<iostream>
#include<climits>
using namespace std;
 
void swap(int *x, int *y);

class MinHeap
{
    int *a; 		// pointer to array of elements in heap
    int count; 	// maximum possible size of min heap
    int MAX; 	// Current number of elements in min heap
	
	public:
    
    MinHeap(int count);
 
    void MinHeapify(int);
 
    int parent(int i)
	{ 
		return (i-1)/2;
	}
 
    int left(int i)
	{
		return (2*i + 1);
	}
 
    int right(int i)
	{ 
		return (2*i + 2);
	}
	
	int extractMin();//delete a[0] and put a[0]=a[count-1]
	void decreaseKey(int i, int new_val);//replace
	int getMin()
	{ 
		return a[0];
	}
	void deleteKey(int i);
	void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
    count = 0;
    MAX = cap;
    a = new int[cap];
}
 
void MinHeap::insertKey(int e)
{
    if (count == MAX)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
 
    // First insert the new key at the end
    count++;
    int i = count - 1;
    a[i] = e;
 
    // Fix the min heap property if it is violated
    while (i != 0 && a[parent(i)] > a[i])
    {
       swap(&a[i], &a[parent(i)]);
       i = parent(i);
    }
}
 
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)//replace
{
    a[i] = new_val;
    while (i != 0 && a[parent(i)] > a[i])
    {
       swap(&a[i], &a[parent(i)]);
       i = parent(i);
    }
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (count <= 0)
        return -1;
    if (count == 1)
    {
        count--;
        return a[0];
    }
 
    // Store the minimum value, and remove it from heap
    int root = a[0];
    a[0] = a[count-1];
    count--;
    MinHeapify(0);
    return root;
}
 
 
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);//it replace the a[i] with INT_MIN and then INT_MIN reach to the top
    extractMin();//it replace the last value with top value and return 
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified(very important)
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < count && a[l] < a[i])//left child with root
        smallest = l;
    if (r < count && a[r] < a[smallest])//right child with (min(left child,root))
        smallest = r;
    if (smallest != i)//if(root!=smallest)
    {
        swap(&a[i], &a[smallest]);
        MinHeapify(smallest);
    }
}
 
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// Driver program to test above functions
int main()
{
    MinHeap h(100);
    h.insertKey(35);
    h.insertKey(23);
	h.insertKey(42);
	h.insertKey(10);
	h.insertKey(14);
	h.insertKey(19);
	h.insertKey(27);
	h.insertKey(44);
	h.insertKey(26);
	h.insertKey(31);
	h.deleteKey(1);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}

/*
Output:
10 19 1
*/