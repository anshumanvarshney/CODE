/*
Find repeated number in O(n) time with O(1) space

if time complexity is O(n) for both space and time then we can use
count arr method i.e arr[a[i]++;
*/
//good concept
#include<bits/stdc++.h>
using namespace std;

void printRepeating(int arr[], int size)
{
  int i;  
  
  printf("\n The repeating elements are");
   
  for(i = 0; i < size; i++)
  {
    if(arr[abs(arr[i])] > 0)
      arr[abs(arr[i])] = -arr[abs(arr[i])];
    else
      printf(" %d ", abs(arr[i]));
  }         
}     
 
int main()
{
  int arr[] = {1, 3, 2, 2, 1};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printRepeating(arr, arr_size);
  return 0;
}