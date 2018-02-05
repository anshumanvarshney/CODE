/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:
- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

Sample Input 0
2
1 2

Sample Output 0
3

Explanation 0
The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
So rating 2 candidate gets 2 candies. In total, 2+1 = 3 candies need to be given out.

test cases
1 2 3 4 5 4 3
(1 2 3 4 5 2 1)
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n,a[1000000],l[1000000],r[1000000],i,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        l[i]=r[i]=1;//min one candy
    for(i=0;i<n;i++)
    {
        if(a[i]<a[i+1])
            l[i+1]=l[i]+1;
    }
    for(i=n-1;i>=0;i--)
    {
        if(a[i-1]>a[i])
            r[i-1]=r[i]+1;
    }
    for(i=0;i<n;i++)
    {
        sum+=max(l[i],r[i]);
    }
    cout<<sum;
    return 0;
}
