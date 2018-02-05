/*
Relative Sorting

Given two array A1[] and A2[], sort A1 in such a way that the relative order among the elements will be 
same as those  in A2. For the elements not present in A2. Append them at last in sorted order. 
It is also given that the number of elements in A2[] are smaller than or equal to number of elements in 
A1[] and A2[] has all distinct elements.

Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
       A2[] = {2, 1, 8, 3}
Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}

Since 2 is present first in A2[], all occurrences of 2s should appear first in A[], then all occurrences 
1s as 1 comes after 2 in A[]. Next all occurrences of 8 and then all occurrences of 3.  
Finally we print all those elements of A1[] that are not present in A
*/


/*
Algo:
Let size of A1[] be m and size of A2[] be n.
1) Create a temporary array temp of size m and copy contents of A1[] to it.
2) Create another array visited[] and initialize all entries in it as false. visited[] is used 
to mark those elements in temp[] which are copied to A1[].
3) Sort temp[]
4) Initialize the output index ind as 0.
5) Do following for every element of A2[i] in A2[]
…..a) Binary search for all occurrences of A2[i] in temp[], if present then copy all occurrences to A1[ind]
 and increment ind. Also mark the copied elements visited[]
6) Copy all unvisited elements from temp[] to A1[].
*/

#include<bits/stdc++.h>
using namespace std;

int found(int a[],int e,int n,int vis[])
{
    int i,c=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==e)
        {
            vis[i]=1;
            c++;
        }
    }
    return c;
}

void check(int a[],int n,int b[],int m)
{
    int temp[1000],vis[1000],i,j,ind=0;
    for(i=0;i<n;i++)
    {
        temp[i]=a[i];
        vis[i]=0;
    }
    sort(temp,temp+n);
    for(i=0;i<m;i++)
    {
        int t=found(temp,b[i],n,vis);//no. of occurence by using binary search
        for(j=0;j<t;j++)
        {
            a[ind++]=b[i];
        }
    }
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            a[ind++]=temp[i];
        }
    }
    for(i=0;i<ind;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    
}

int main()
 {
	//welcome Anshuman Varshney
	int p;
	cin>>p;
	while(p--)
    {
        int n,m;
        cin>>n>>m;
        int a[1000],b[1000],i;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<m;i++)
            cin>>b[i];
        check(a,n,b,m);    
    }
	return 0;
}