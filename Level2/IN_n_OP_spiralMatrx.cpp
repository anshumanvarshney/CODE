/*
Print n x n spiral matrix using O(1) extra space
Given a number n, print a n x n spiral matrix (of numbers from 1 to n x n) in clockwise direction using O(1) space.

Input: n = 5

Output:

25  24 23 22 21 
10  9  8  7  20 
11  2  1  6  19 
12  3  4  5  18 
13  14 15 16 17



		25 24 23 22 21
10  		9  8  7 20
11  2 		   1  6 19
12  3  4  		  5 18
13 14 15 16         17


// x stores the layer in which (i, j)th
// element lies
int x;
 
// Finds minimum of four inputs
x = min(min(i, j), min(n-1-i, n-1-j));

For upper right half,
mat[i][j] = (n-2*x)*(n-2*x)-(i-x)-(j-x)

For lower left half,
mat[i][j] = (n-2*x-2)*(n-2*x-2) + (i-x) + (j-x)


Sample Input 1

5
Sample Output 1

1 2 3 4 5 
16 17 18 19 6 
15 24 25 20 7 
14 23 22 21 8 
13 12 11 10 9 

for this subtract from n*n+1
  if (i <= j)
    cout<<(sq*sq+1)-((n-2*x)*(n-2*x) - (i-x)- (j-x))<<" ";
 else
    cout<<(sq*sq+1)-((n-2*x-2)*(n-2*x-2) + (i-x) + (j-x))<<" ";
*/


#include<bits/stdc++.h>
using namespace std;

void printSpiral(int n)
{
    int sq=n; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
			// x stores the layer in which (i, j)th element lies
            int x;
			// Finds minimum of four inputs
            x = min(min(i, j), min(n-1-i, n-1-j));
			
			//For upper right half,
            if (i <= j)
                cout<<(((n-2*x)*(n-2*x) - (i-x)- (j-x))<<" ";
			//For lower left half,
            else
               cout<<((n-2*x-2)*(n-2*x-2) + (i-x) + (j-x))<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    printSpiral(n);
    return 0;
}