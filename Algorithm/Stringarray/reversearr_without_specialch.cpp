/*
Algo
Simple Solution:

1) Create a temporary character array say temp[].
2) Copy alphabetic characters from given array to temp[].
3) Reverse temp[] using standard string reversal algorithm.
4) Now traverse input string and temp in a single loop. 
Wherever there is alphabetic character is input string, replace it with current character of temp[].

Efficient Solution:
Time complexity of above solution is O(n), but it requires extra space and it does two traversals of input string.
We can reverse with one traversal and without extra space. Below is algorithm.

1) Let input string be 'str[]' and length of string be 'n'
2) l = 0, r = n-1
3) While l is smaller than r, do following
    a) If str[l] is not an alphabetic character, do l++
    b) Else If str[r] is not an alphabetic character, do r--
    c) Else swap str[l] and str[r]
*/
/*
#include<iostream>
#include<ctype.h>
using namespace std;

int main()
{
	char a[20];
	int i,n,l,r;
	gets(a);
	for(i=0;a[i]!='\0';i++)
		cout<<a[i];
	cout<<"\n";
	for(n=0;a[n]!='\0';n++);
	l=0;
	r=n-1;
	
	while(l < r)
	{
		if(!isalpha(a[l])) 
			l++;
		else if(!isalpha(a[r]))
			r--;
		
		else
		{		char t=a[l];
				a[l]=a[r];
				a[r]=t;
				l++;
				r--;
		}
	}
	puts(a);
}

*/


OR

/*#include<iostream>
#include<ctype.h>
using namespace std;

int main()
{
	char a[10],b[10];
	int i,l,t,r,n,j=0,k=0;
	gets(a);
	for(n=0;a[n]!='\0';n++);
	l=0;
	r=n-1;
	while(l<r)
	{
		while(!isalpha(a[l]))
	     l++;
	    while(!isalpha(a[r]))
			r--;
		
					
			t=a[l];
			a[l]=a[r];
			a[r]=t;
			l++;
			r--;
				
    }
     puts(a);
		
	return 0;
}*/



#include<iostream>
using namespace std;

int main()
{
	char a[20],b[20];
	int i,j,k,l,n;
	gets(a);
	for(i=0;a[i]!='\0';i++)
		cout<<a[i];
	cout<<"\n";
	for(n=0;a[n]!='\0';n++);
	k=0;
	for(i=n-1;i>=0;i--)
	{
		//if((a[i]>='a' || a[i]>='A') && (a[i]<='z' || a[i]<='Z'))//or 
		if(isalpha(a[i]))
		{
			b[k]=a[i];
			k++;
		}
	}
	j=0;
	for(i=0;i<n;i++)
	{
		if(isalpha(a[i])
		{
			a[i]=b[j];
			j++;
		}
	}
	puts(a);
}

