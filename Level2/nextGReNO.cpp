/*
Find next greater number with same set of digits
Given a number n, find the smallest number that has same set of digits as n and is greater than n.
If x is the greatest possible number with its set of digits, then print “not possible”.

Examples:
For simplicity of implementation, we have considered input number as a string.

Input:  n = "218765"
Output: "251678"

Input:  n = "1234"
Output: "1243"

Input: n = "4321"
Output: "Not Possible"

Input: n = "534976"
Output: "536479"

Algorithm
Following are few observations about the next greater number.
1) If all digits sorted in descending order, then output is always “Not Possible”. For example, 4321.
2) If all digits are sorted in ascending order, then we need to swap last two digits. For example, 1234.
3) For other cases, we need to process the number from rightmost side (why? because we need to find the 
smallest of all greater numbers)

Following is the algorithm for finding the next greater number.
I) Traverse the given number from rightmost digit, keep traversing till you find a digit which is smaller 
than the previously traversed digit. For example, if the input number is “534976”, we stop at 4 because 4 
is smaller than next digit 9. If we do not find such a digit, then output is “Not Possible”.

II) Now search the right side of above found digit ‘d’ for the smallest digit greater than ‘d’.
 For “534976″, the right side of 4 contains “976”. The smallest digit greater than 4 is 6.

III) Swap the above found two digits, we get 536974 in above example.

IV) Now sort all digits from position next to ‘d’ to the end of number. The number that we get after 
sorting is the output. For above example, we sort digits in bold 536974. We get “536479” which is the
 next greater number for input 534976.
*/

/*
Input
2
143
431

Output
314
not possible
*/

#include<bits/stdc++.h>
using namespace std;

string check(string a)
{
	int n=a.length();
	int i;
	for(i=n-1;i>=0;i--)
	{
		if(a[i]>a[i-1])
			break;
	}
	if(i==0)
		return "not possible";
	/*else if(i==n-1)
	{
		swap(a[n-2],a[n-1]);
		return a;
	}*/
	else 
	{
		sort(a.begin()+i,a.end());
		int t=i-1;
		for(int k=i;k<n;k++)
		{
			if(a[t]<a[k])//eg : 278765 to 285677
			{
				swap(a[k],a[t]);
				break;
			}
		}
		return a;
	}
	
	/*else part
	
	int x = number[i-1], smallest = i;
    // x=a[2]=4 and smallest = index 3
	
	for (j = i+1; j < n; j++)
        if (number[j] > x && number[j] < number[smallest])////eg : 278765 to 285678
            smallest = j;//now we get smallest =index 5
 
    // III) Swap the above found smallest digit with number[i-1]
    swap(&number[smallest], &number[i-1]);//here we get no: 5 3 6 9 7 4
 
    // IV) Sort the digits after (i-1) in ascending order
    sort(number + i, number + n);//now we get no: 5 3 6 4 7 9
 
	cout << "Next number with same set of digits is " << number;
	*/
}
int main()
{
	int p;
	cin>>p;
	while(p--)
	{
		string a;
		cin>>a;
		cout<<check(a)<<"\n";
	}
}