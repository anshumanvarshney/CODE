/*
The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.

Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, 
and which will cause the eggs to break on landing i.e which floor the egg will break.


Question is : Given some egg and certain numbers of floors what is minimum attempt to
find out in worst case from which floor the egg will break
 
We make a few assumptions:

…..An egg that survives a fall can be used again.
…..A broken egg must be discarded.
…..The effect of a fall is the same for all eggs.
…..If an egg breaks when dropped, then it would break if dropped from a higher floor.
…..If an egg survives a fall then it would survive a shorter fall.
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the
 36th-floor do not cause an egg to break.

--> If only one egg is available and we wish to be sure of obtaining the right result,
	the experiment can be carried out in only one way. Drop the egg from the first-floor window;
	if it survives, drop it from the second floor window. 
	Continue upward until it breaks. In the worst case, this method may require 36 droppings. 
	so ans is 36

-->	Suppose 2 eggs are available.
	What is the least number of egg-droppings that is guaranteed to work in all cases?

The problem is not actually to find the critical floor, but merely to decide floors from 
which eggs should be dropped so that total number of trials are minimized.

Explanation:

there will be two situation eggbreaks or egg does not breaks
i.e if 1 egg and 10 floor
  so min attempt  =10
if 10 egg and 1 floor 
   then min attempt =1 
   
now suppose there are 2 egg and 10 floor
and we try from 4th floor
if egg breaks then egg left out =1 and floor left out =3 
if egg does not break the egg left out =2 and floor left out=10-4

so n egg and x floor and we try from kth floor
if egg breaks n-1,k-1
if not break  n,k-x

algo dp:
			1	2	3	4	5<-- floors
		1	1	2	3	4	5
->Egg	2	1
		3	1
	initially filled by boundry condition
	as n floor 1 egg then n attemp 
	as 1 floor n egg then 1 attempt
*/

#include<bits/stdc++.h>
using namespace std;

int eggDrop(int n,int k)
{
	int a[n+1][k+1],i,j,x,res;
	for(i=1;i<=n;i++)
	{
		a[i][1]=1;
		//a[i][0]=0; no need
	}
	for(j=1;j<=k;j++)
	{
		a[1][j]=j;
	}
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=k;j++)
		{
			a[i][j]=INT_MAX;
			for(x=1;x<=j;x++)//this is for checking form 1 floor to j floor 
			{
				res= 1 + max(a[i-1][x-1],a[i][j-x]);//break and not break case
				if(res < a[i][j])//taking min of all the cases(because we have to find minimum attempt)
					a[i][j]=res;
			}
		}
	}
	return a[n][k];
}

int main()
{
    int n = 2, k = 36;
	cout<<eggDrop(n, k)<<"\n";
    return 0;
}
