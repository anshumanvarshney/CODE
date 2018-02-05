#include<bits/stdc++.h>
using namespace std;
/*
int squrt(int n)
{
	int i,result;
	if(n==1) return 1;
	for(i=1;i<=n/2;i++)
	{
		if(i*i<=n)
		{
			result = i;
		}
	}
	return result;
}
*/
int squrt(int A)
{
   long long B=A;
   long long l=0,r=A;
   long long mid;
   long long sq;
   while(l<=r){
       mid=(l+r)/2;
       sq=mid*mid;
       if(sq==B)
            return (int)mid;
        else if(sq<B)
            l=mid+1;
        else r=mid-1;
   }
   return (int)r;
}

int main()
{
	int n;
	cin>>n;
	int t=squrt(n);
	if(t==0)
		cout<<"\nEnter proper number\n";
	else cout<<t<<"\n";
}