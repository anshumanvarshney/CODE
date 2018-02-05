/*
Check length of a string is equal to the number appended at its last
Given a string that (may) be appended with a number at last. You need to find whether the length 
of string excluding that number is equal to that number. For example for “helloworld10”, answer
 is True as helloworld consist of 10 letters. Length of String is less than 10,000.

Examples:

Input:  str = "geeks5"
Output:  Yes
Explanation : As geeks is of 5 length and at 
              last number is also 5.

Input:  str = "geeksforgeeks15"
Output:  No
Explanation: As geeksforgeeks is of 13 length and
             at last number is 15 i.e. not equal
			 
*/			 

#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//welcome Anshuman Varshney
	int p;
	cin>>p;
	while(p--)
	{
	    string str;
	    cin>>str;
	    int n = str.length();

        int num = 0, x = 1, i = n-1;
        for (i=n-1; i>=0; i--)//reverse loop
        {
            if (str[i]>='0' &&  str[i]  <= '9')
            {
                num = (str[i] - '0')*x + num;
                x = x * 10;
            }
            else break;
        }
	  
	    if(num==i+1)
	        cout<<1;
	    else cout<<0;
	    cout<<"\n";
	}
	return 0;
}