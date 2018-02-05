/*

Given an interger N, how many structurally unique binary search trees are there that store values 1...N?

For example, for N = 2, there are 2 unique BSTs
     1               2  
       \           /
       2         1
For N = 3, there are 5 possible BSTs
  1              3        3         2      1
    \           /        /       /    \      \
     3        2         1       1      3      2
    /       /            \                      \
   2      1               2                        3

My algo:
(2n)C(n)/(n+1;   
   
   Total no of Binary Trees are = (2n)!/n!*(n+1)!
   base case t(0)=t(1)=1
   t(2)=t(0)t(1) + t(1)t(0)
   t(3)=t(0)t(2) + t(1)t(1) + t(2)t(0)
   t(4)=t(0)t(3) + t(1)t(2) + t(2)t(1) + t(3)t(0)

(1/(n+1))*(2nCn)
or
(2n)!/n!*(n+1)!

where C=combination eg.

n=6,
possible binary trees=(1/7)*(12C6)=132
   */

#include<bits/stdc++.h>
using namespace std;
//only applicable for 6 vertices because size is too large to handle
/*int fact(int n)
{
	int i;
	if(n<=2) return n;
	long long a=n;
	for(i=2;i<n;i++)
	{
		a*=i;
	}
	return a;
}

int nbst(int n)
{
	if(n == 0 || n == 1 || n == 2)
	return n;
	long long a,b,c;
	a=fact(2*n);
	b=fact(n);
	c=fact(n+1);
	cout<<a<<" "<<b<<" "<<c<<"\n";
	
	//int d=b*c;
	return a/b;
}*/
/*
//using dp
int nbst(int n)
{
	if(n == 0 || n == 1 || n == 2)
        return n;
    int *bst;
	bst= new int[n+1];
    bst[0] = 1;
    bst[1] = 1;
    bst[2] = 2;
    for (int i=3; i<=n; i++)
	{
        for (int j=1; j<i-1; j++) 
		{
            bst[i] += bst[j]*bst[i-1-j]; //t(1)*t(2) + t(2)*t(1)
        }
        bst[i] += 2*bst[i-1]; //t(3)*(0) + t(0)(3);
    }
    return bst[n];
}
*/

//my algo
//find nCr for lucas algo
int comb(int a,int b)
{
	int *arr,i,j;
	arr=new int[a];
	for(i=0;i<a;i++)
	{
		arr[i]=0;
	}
	arr[0]=arr[1]=1;
	for(j=2;j<=a;j++)
	{
		for(i=min(j,b);i>0;i--)
		{
			arr[i]=arr[i]+arr[i-1];
		}
	}
	return arr[b];
}

int nbst(int n)
{
	if(n == 0 || n == 1 || n == 2)
        return n;
	int a,b;
	a=2*n;
	b=n;
	int c=comb(a,b);
	return c/(n+1);
}
int main()
{
	int p,n;
	cin>>p;
	while(p--)
	{
		cin>>n;
		cout<<nbst(n)<<"\n";
	}
}
