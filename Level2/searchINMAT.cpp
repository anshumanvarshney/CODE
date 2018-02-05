/*
Search in a row wise and column wise sorted matrix
Given an n x n matrix and a number x, find position of x in the matrix if it is present in it.
 Else print “Not Found”. In the given matrix, every row and column is sorted in increasing order.
 The designed algorithm should have linear time complexity.

Example :

Input : mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 29
Output : Found at (2, 1)

Input : mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 100
Output : Element not found
*/

// C program to search an element in row-wise
// and column-wise sorted matrix
#include<stdio.h>
 
/* Searches the element x in mat[][]. If the 
   element is found, then prints its position 
   and returns true, otherwise prints "not found"
   and returns false */
int search(int mat[4][4], int n, int x)
{
   int i = 0, j = n-1;  //set indexes for top right element
   while ( i < n && j >= 0 )
   {
      if ( mat[i][j] == x )
      {
         printf("n Found at %d, %d", i, j);
         return 1;
      }
      if ( mat[i][j] > x )
        j--;
      else //  if mat[i][j] < x
        i++;
   }
 
   printf("n Element not found");
   return 0;  // if ( i==n || j== -1 )
}
 
// driver program to test above function
int main()
{
  int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  search(mat, 4, 29);
  return 0;
}
/*
Run on IDE
Output :

Found at 2, 1
Time Complexity: O(n)
*/