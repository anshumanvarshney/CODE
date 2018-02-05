/*
int main()
{
    printPattern("geeksforgeeks");
    return 0;
}
Run on IDE
Output:

g           s
 e         k
  e       e
   k     e
    s   g
     f r
      o
     f r
    s   g
   k     e
  e       e
 e         k
g           s


*/

#include<iostream>
using namespace std;
//my algo O(n^2)
int main()
{
	char a[]={"geeksforgeeks"};
	char x,y;
	int n=sizeof(a)/sizeof(char);
	int i,j,k;
	i=0,j=n-2;
	//cout<<a[0]<<" "<<a[n-2];//check this out
	while(i<=j)
	{
		for(int l=0;l<=i;l++)
				cout<<" ";
		if(i!=j)
		{
			x=i;
			y=j;
			
			cout<<a[i];
			for(k=i;k<j;k++)
				cout<<" ";
			cout<<a[j];
		}
		else cout<<a[i];
		i++,j--;
		cout<<"\n";
	}
	for(i=x,j=y;i>=0;i--,j++)
	{
		for(int l=0;l<=i;l++)
				cout<<" ";
			cout<<a[i];
			for(k=i;k<j;k++)
				cout<<" ";
			cout<<a[j];
			cout<<"\n";
	}
	return 0;
}