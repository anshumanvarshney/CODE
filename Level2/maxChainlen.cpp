/*
Dynamic Programming | Set 20 (Maximum Length Chain of Pairs)
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number. 
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion.
 Find the longest chain which can be formed from a given set of pairs.

For example, if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }, then the longest
 chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}

 Input
2
5
5 24 39 60 15 28 27 40 50 90
2
5 10 1 11 

Output
3
1
​
 */

struct val
{
  int first;
  int second;
};


bool compare(val v1,val v2)
{
    return (v1.second<v2.second);
}

int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,compare);
    int i,j,k,count=0;
    i=0;
    count++;
    for(j=1;j<n;j++)
    {
        if(p[j].first >p[i].second)
        {
            count++;
            i=j;
        }
    }
    return count;
}
 
 
int main()
{
    struct pair arr[] = { {5, 24}, {15, 25},
                          {27, 40}, {50, 60} };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of maximum size chain is %d\n",
           maxChainLen( arr, n ));
    return 0;
}
