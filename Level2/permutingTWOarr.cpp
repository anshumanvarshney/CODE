/*
Permute two arrays such that sum of every pair is greater or equal to K
Given two arrays of equal size n and an integer k. The task is to permute both arrays 
such that sum of their corresponding element is greater than or equal to k i.e a[i] + b[i] >= k. 
The task is print “Yes” if any such permutation exists, otherwise print “No”.

Examples:

Input : a[] = {2, 1, 3}, 
        b[] = { 7, 8, 9 }, 
        k = 10. 
Output : Yes
Permutation  a[] = { 1, 2, 3 } and b[] = { 9, 8, 7 } 
satisfied the condition a[i] + b[i] >= K.

Input : a[] = {1, 2, 2, 1}, 
        b[] = { 3, 3, 3, 4 }, 
        k = 5. 
Output : No

Sample Input

2
3 10
2 1 3
7 8 9
4 5
1 2 2 1
3 3 3 4
Sample Output

YES
NO

*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int p;
    cin>>p;
    while(p--)
    {
        long long int n,k,a[100000],b[100000],i;
        cin>>n>>k;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        long long int c=0;
        for(i=0;i<n;i++)
        {
            if((a[i]+b[i])>=k)
                c++;
        }
        if(c>=n)
            cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}
