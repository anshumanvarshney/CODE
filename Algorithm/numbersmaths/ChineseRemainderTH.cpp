/*
Chinese Remainder Theorem | Set 1 (Introduction)
We are given two arrays num[0..k-1] and rem[0..k-1]. In num[0..k-1], every pair is coprime 
(gcd for every pair is 1). We need to find minimum positive number x such that:

     x % num[0]    =  rem[0], 
     x % num[1]    =  rem[1], 
     .......................
     x % num[k-1]  =  rem[k-1] 
Basically, we are given k numbers which are pairwise coprime, and given remainders of these
 numbers when an unknown number x is divided by them. We need to find the minimum possible 
 value of x that produces given remainders.

Examples:

Input:  num[] = {5, 7}, rem[] = {1, 3}
Output: 31
Explanation: 
31 is the smallest number such that:
  (1) When we divide it by 5, we get remainder 1. 
  (2) When we divide it by 7, we get remainder 3.

Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}
Output: 11
Explanation: 
11 is the smallest number such that:
  (1) When we divide it by 3, we get remainder 2. 
  (2) When we divide it by 4, we get remainder 3.
  (3) When we divide it by 5, we get remainder 1.
 algo:
 
 A Naive Approach to find x is to start with 1 and one by one increment it and check if 
 dividing it with given elements in num[] produces corresponding remainders in rem[].
  
  Algo:
  
  */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={5,7};
	int b[]={1,3};
	int m=sizeof(a)/sizeof(int);
	int n=1,i=0;
	while(1)
	{
		if((n%a[i])==b[i])
		{
			i++;
			if(i==m)
			{
				cout<<n;
				break;
			}
		}
		else
		{
			n++;
			i=0;
		}
	}
	
	return 0;
}