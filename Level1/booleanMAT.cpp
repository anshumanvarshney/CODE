/*
Boolean Matrix Problem

Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 
(or true) then make all the cells of ith row and jth column as 1

Input:
3
2 2
1 0 0 0
2 3
0 0 0 0 0 1
3 4
1 0 0 1 0 0 1 0 0 0 0 0

Output:
1 1 1 0
0 0 1 1 1 1
1 1 1 1 1 1 1 1 1 0 1 1

*/

#include<bits/stdc++.h>
using namespace std;


int main()
 {
	//welcome Anshuman Varshney
	int n,m,p,a[100][100],b[100][100],i,j,k,x,y;
	cin>>p;
	while(p--)
	{
	    cin>>n>>m;
	    for(i=0;i<n;i++)
	        for(j=0;j<m;j++)
	            cin>>a[i][j];
	       
	    for(i=0;i<n;i++)
	        for(j=0;j<m;j++)
	            b[i][j]=a[i][j];         
	            
	            
	            
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            if(a[i][j]==1)
	            {
                    x=i;
                    y=j;
                    for(k=0;k<m;k++)
	                    b[x][k]=1;
	                for(k=0;k<n;k++)
	                    b[k][y]=1;
	            }
	            
	        }
	     }
	     for(i=0;i<n;i++)
	        for(j=0;j<m;j++)
	            cout<<b[i][j]<<" ";
	       cout<<"\n";     
	    
	}
	
	return 0;
}