/*
Your task is simple (lol). Given N numbers, print them in ascending order.
You may use any sorting algorithm.

Constraints
1 <= N = 2x10^5 
1 <= ar <= 10^(10^6) 
The total number of digits across all the elements of the array will not exceed 10^6.

Sample Input 0

6
31415926535897932384626433832795
1
3
10
3
5
Sample Output 0

1
3
3
5
10
31415926535897932384626433832795
*/

/*
#include <bits/stdc++.h>
using namespace std;


bool compare(string a,string b)
{
    if(a.size()!=b.size())
        return a.size() < b.size();
    return a < b;
    
}
int main() 
{ 
    int n,i,j;
    cin>>n;
    string s[200000];
    vector<string> v;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end(), compare);
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\n";
    }

    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

bool compare(string a,string b)
{
    if(a.size()!=b.size())
        return a.size() < b.size();
    return a < b;
    
}
void print(string a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\n";
}

int pivot(string a[],int l,int h,int n)
{
    int i,j;
    string piv=a[h];
    i=l-1;
    for(j=l;j<h;j++)
    {
        if(compare(a[j],piv))//if(a[j]>piv) in normal sort
        {
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i+1],a[h]);
    return (i+1);
    
}
void qisort(string a[],int l,int h,int n)
{
    if(l<h)
    {
        int i=pivot(a,l,h,n);
        qisort(a,l,i-1,n);
        qisort(a,i+1,h,n);
       
    }
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,j;
    cin>>n;
    string s[200000];
    for(i=0;i<n;i++)
        cin>>s[i];
    qisort(s,0,n-1,n);
    print(s,n); 

    return 0;
}
