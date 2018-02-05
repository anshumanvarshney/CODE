//time complexity =O(n)

/*#include<iostream>
using namespace std;

int main()
{
	int *a,i,n,x,f=0;
	cout<<"Enter size of the array :";
	cin>>n;
	a=new int [n];
   cout<<"\nEnter elements :";
   for(i=0;i<n;i++)
   {
	   cin>>a[i];
   }
   cout<<"\nEnter the element to be search :";
   cin>>x;
   for(i=0;i<n;i++)
   {
	   if(a[i]==x)
	   {
		   f=1;
		   break;
	   }
   }
   if(f==0)
	   cout<<"\nElement not found ";
   else
       cout<<"\nElement found at position :"<<i+1;
   delete [] a;
   
}*/#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int i,n,x,a,f=0;
	vector<int> v;
	cout<<"Enter size :";
	cin>>n;
	cout<<"\nEnter element :";
	for(i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	cout<<"\nEnter the element to be search :";
	cin>>x;
	for(i=0;i<n;i++)
	{
		int data=v.back();
		if(data==x)
		{
			f=1;
			break;
		}
		v.pop_back();
		
	}
	if(f==1)
		cout<<"\nFound";
	else cout<<"\nNot found";
}



