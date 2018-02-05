/*
In a village,there are n farmers. Each farmer has a certain number of cows. You have to find the number of triplets of 
farmers such that the number of cows of one farmer is the sum of the cows of other two farmers.
*/

#include <bits/stdc++.h>
using namespace std;
//O(n*n*log(n))
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int a[100000],n,i,j,c=0,k;
    cin>>n;
    
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
			if(binary_search(a, a + n, a[i]+a[j])) 
                    c++;
            
        }
    }
   
    cout<<c;
    return 0;
}

//O(n*n)

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int a[100000],n,i,j,c=0,k;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    unordered_set<int> s;
    for(i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s.find(a[i]+a[j])!=s.end())       
                    c++;
            
        }
    }
   
    cout<<c;
    return 0;
}