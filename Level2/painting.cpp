/*
There are n pictures delivered for the new exhibition. The i-th painting has beauty ai. We know that a visitor
 becomes happy every time he passes from a painting to a more beautiful one.

We are allowed to arranged pictures in any order. What is the maximum possible number of times the visitor 
may become happy while passing all pictures from first to last. In other words, we are allowed to rearrange 
elements of array a in any order. 
What is the maximum possible number of indices i (1 <= i <= n - 1), such that ai + 1 > ai.


Sample Input 0

4
200 100 100 200
Sample Output 0

2
Explanation 0

Sample Ordering that gives answer 2 :

100 200 100 200
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, a[1000],b[1000],j,i,c=0,m;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
          if(a[i]==a[i+1])
            c++;
          else
          {
            m=max(c+1,m);
            c=0;
          }
    }
    
   cout<<(n-m);
    
    return 0;
}

