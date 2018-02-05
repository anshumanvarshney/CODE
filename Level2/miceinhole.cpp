/*
There are N Mice and N holes are placed in a straight line.
Each hole can accomodate only 1 mouse.
A mouse can stay at his position, move one step right from x to x + 1, or move one step left from x to x − 1. 
Any of these moves consumes 1 minute.
Assign mice to holes so that the time when the last mouse gets inside a hole is minimized.

Sample Input 0
3
4 -4 2
4 0 5

Sample Output 0
4
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,a[100000],b[100000],c[100000],i,m=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
     for(i=0;i<n;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    
    for(i=0;i<n;i++)
    {
        m=max(m,abs(a[i]-b[i]));
    }
    cout<<m;
    return 0;
}