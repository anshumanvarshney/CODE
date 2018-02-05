#include<iostream>
using namespace std;

int main()
{
	int a[5][5],i,j;
	cout<<"Enter Matrix :";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"\nMatrix Are :\n";
	for(i=0;i<3;i++)
	{
		cout<<"[ ";
		for(j=0;j<3;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"]\n";
	}
	int k=a[0][0];
	int c=0,d=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
	    {
		   if(i==j)
		   {
			  if(a[i][j]==k)
			  {
				  c++;
			  }				  
		   }
            else 
             if(a[i][j]!=0)
             {
				 d++;
			 }				 
	    }
	}
	if(c==3&&d==0)
	{
		cout<<"\nMatrix is Scalar";
	}
	else cout<<"\nMatrix is not scalar ";
}

/*
for(i=0;i<3;i++)
{
	if(a[i][i]==k)
	{
		c++;
	}				  
		   
    else 
             if(a[i][j]!=0)
             {
				 d++;
			 }
	if(c==3&&d==0)
	{
		cout<<"\nMatrix is Scalar";
	}
	else cout<<"\nMatrix is not scalar ";
}
*/