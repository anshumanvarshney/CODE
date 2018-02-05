#include<iostream.h>
#include<conio.h>

int main()
{
 clrscr();
 int a[10],i,j,t,n;
 cout<<"Input\n";
 cin>>n;
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 for(i=n-1;i>=0;i--)
 {
    cout<<a[i]<<" ";
 }
 return 0;
}
/*
#include<iostream>
using namespace std;


int main()
{
    int n,i,j;
    cin >> n;
    int *p;
    p=new int[n];
    for(i=0;i<n;i++)
    {
        cin>>*(p+i);
    }
    for(i=n-1;i>=0;i--)
    {
		cout<<*(p+i)<<" " ;
	}
    delete [] p;
	return 0;
}
 /*
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
       cin >> a[i];
    }
     for(int i = n-1;i >= 0;i--){
       cout<<a[i]<<" ";
    }
    
    return 0;
}
*/ 

*/