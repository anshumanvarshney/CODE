/*Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

My algo:
eg array =={3,30,34,5,9}
convert into {7,10,6,5,1} by subtracting from its 10's part 
now sort the array {1,5,6,7,10} 
now form a number by r=r*10+d

Input:

2
5
3 30 34 5 9
4
54 546 548 60

Output:

9534330
6054854654
*/

int compare (string a, string b)
{
    string ab=a+b;
    string ba=b+a;
    if(ab>ba)
        return 1;
    else return 0;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        
    }
    sort(s, s+n, compare);
    for(int i=0;i<n;i++)
        cout<<s[i];
 
    return 0;
}


bool compare(string a,string b)
{
    string s1=a+b;
    string s2=b+a;
    if(s1>s2)
        return true;
    else return false;    
}

string Solution::largestNumber(const vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int n=a.size();
    string s[n];
    for(int i=0;i<n;i++)
        s[i]=to_string(a[i]);
    sort(s,s+n,compare);
    string res="";
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=="0")
            c++;
        res+=s[i];
    }
    if(c==n)
        return "0";
    return res;
}6..