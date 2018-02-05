/*
N light bulbs are connected by a wire. Each bulb has a switch associated with it, however due to faulty wiring,
a switch also changes the state of all the bulbs to the right of current bulb. Given an initial state of all bulbs,
find the minimum number of switches you have to press to turn on all the bulbs. You can press the same switch multiple times.

Note : 0 represents the bulb is off and 1 represents the bulb is on.

Output Format

Output the minimum number of switches you'll need to press.

Sample Input 0

4
0 1 0 1
Sample Output 0

4
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,a[100000],c=0,i;
    bool flag=false;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        if(a[i]==flag)
        {
            c++;
            flag=!flag;
        }
    }
    cout<<c;
    return 0;
}
