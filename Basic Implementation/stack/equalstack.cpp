/*
#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<int> s1,s2,s3;
    int n1,n2,n3,e,i,m1=0,m2=0,m3=0;
    cin>>n1>>n2>>n3;
    for(i=0;i<n1;i++)
        {
        cin>>e;
		m1+=e;
        s1.push(e);
    }
    for(i=0;i<n2;i++)
        {
        cin>>e;
		m2+=e;
        s2.push(e);
    }
    for(i=0;i<n3;i++)
        {
        cin>>e;
		m3+=e;
        s3.push(e);
    }
	while(m1!=m2&&m2!=m3)
	{
	    if(m1>m2&&m1>m3)
		{
			int data=s1.top();
			s1.pop();
			m1-=data;
		}
		else  if(m2>m1&&m2>m3)
		{
			int data=s2.top();
			s2.pop();
			m2-=data;
		}
		else  if(m3>m1&&m3>m1)
		{
			int data=s1.top();
			s3.pop();
			m3-=data;
		}
			
	}
	cout<<m2;
	return 0;
}

*/
//you can do nit by using queue also
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    vector<int> s1,s2,s3;
    int n1,n2,n3,e,i,m1=0,m2=0,m3=0;
	cout<<"\nSize 1 :";
    cin>>n1;
	cout<<"\nSize 2 :";
    cin>>n2;
	cout<<"\nSize 3 :";
    cin>>n3;
	cout<<"\nEnter element 1 :";
    for(i=0;i<n1;i++)
        {
        cin>>e;
		m1+=e;
        s1.push_back(e);
    }
    cout<<"\nEnter element 2 :";
    for(i=0;i<n2;i++)
        {
        cin>>e;
		m2+=e;
        s2.push_back(e);
    }
    cout<<"\nEnter element 3 :";
    for(i=0;i<n3;i++)
        {
        cin>>e;
		m3+=e;
        s3.push_back(e);
    }
	cout<<"\nm1="<<m1;
	cout<<"\nm2="<<m2;
	cout<<"\nm3="<<m3;
	
	while(m1!=m2&&m2!=m3)
	{
	    if(m1>m2&&m1>m3)
		{
			int data=s1.front();
            s1.pop_back();
			m1-=data;
		}
		else  if(m2>m1&&m2>m3)
		{
			int data=s2.front();
            s2.pop_back();
			m2-=data;
		}
		else  if(m3>m1&&m3>m1)
		{
			int data=s3.front();
            s3.pop_back();
			m3-=data;
		}
			
	}
	cout<<"\n"<<m2;
	return 0;
}
