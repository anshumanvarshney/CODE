/*
Rotate the Matrix clockwise by an angle of 90 degrees.

Sample Input 0

2
1 2
3 4
Sample Output 0

3 1
4 2
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,j,k,l,a[100][100],c[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        k=0;
        for(j=0;j<n;j++)
        {
            c[k++]=a[j][i];
        }
        for(l=k-1;l>=0;l--)
            cout<<c[l]<<" ";
        cout<<"\n";
            
    }
    
    return 0;
}
