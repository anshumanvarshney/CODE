/*
Count number of ways to fill a “n x 4” grid using “1 x 4” tiles
Given a number n, count number of ways to fill a n x 4 grid using 1 x 4 tiles.

[ | | | ] = 1*4

http://www.geeksforgeeks.org/count-number-of-ways-to-fill-a-n-x-4-grid-using-1-x-4-tiles/  for diagram view
Examples:

Input : n = 1
Output : 1

Input : n = 2
Output : 1
We can only place both tiles horizontally

Input : n = 3
Output : 1
We can only place all tiles horizontally.

Input : n = 4
Output : 2
The two ways are : 
  1) Place all tiles horizontally 
  2) Place all tiles vertically.

Input : n = 5
Output : 3
We can fill a 5 x 4 grid in following ways : 
  1) Place all 5 tiles horizontally
  2) Place first 4 vertically and 1 horizontally.
  3) Place first 1 horizontally and 4 horizontally.

 for 5 
  Algo:
  Let “count(n)” be the count of ways to place tiles on a “n x 4” grid, following two 
  cases arise when we place the first tile.

1  Place the first tile horizontally : If we place first tile horizontally, the problem reduces to “count(n-1)”
2  Place the first tile vertically : If we place first tile vertically, then we must place 3 more tiles vertically.
   So the problem reduces to “count(n-4)”
   
   for diagram
http://www.geeksforgeeks.org/count-number-of-ways-to-fill-a-n-x-4-grid-using-1-x-4-tiles/

Therefore, count(n) can be written as below.

   count(n) = 1 if n = 1 or n = 2 or n = 3   
   count(n) = 2 if n = 4
   count(n) = count(n-1) + count(n-4) 
   
   */
   
   /*
   Example:

Input:
3
1
4
5

Output:
1
2
3
   */
   
#include<bits/stdc++.h>
using namespace std;

int count(int n)
{
	int *a=new int[n+1];
	a[1]=1;
	a[2]=1;
	a[3]=1;
	a[4]=2;
	int i;
	for(i=5;i<=n;i++)
		a[i]=a[i-1]+a[i-4];
	return a[n];
}

int main()
{
	int p,i;
	cin>>p;
	
	while(p--)
	{
		int n;
		cin>>n;
		cout<<count(n)<<"\n";
	}
}