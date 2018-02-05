#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int **a,n,i,j,x=0,y=0,m,o;
    cin>>n;
	a=new int*[n];
	for(int i = 0; i < n; ++i)
      a[i] = new int [n];

    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
	{
		x+=a[i][i];
	}
	for(i=0,j=n-1;i<n;i++,j--)
	{
		y+=a[i][j];
	}
	m=(x>y)?x:y;
	o=(x<y)?x:y;
	cout<<m-o;
	  for(int i = 0; i < n; ++i)
    delete [] a[i];
  delete [] a;

    return 0;
}