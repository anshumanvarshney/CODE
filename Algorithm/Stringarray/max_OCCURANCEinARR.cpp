/*
Maximum occurance of a number
Print the type number of the most common bird; if two or more types of birds are 
equally common, choose the type with the smallest ID number.

Sample Input 0

6
1 4 4 4 5 3
Sample Output 0

4
*/

int main()
{
	int n,i;
	cin >>n;
	int a[2*100000 + 100];//MAXimum size less than range given in the question
	memset(a,0,sizeof(a));
	int my[n];
	for(i = 0;i<n;i++)
	{
		cin >>my[i];
		a[my[i]]++;
	}
	int p,mx=a[0];
	
	for(i = 0;i<n;i++)
	{
		if(mx<a[i])
		{
			mx=a[i];
			p=i;
	    }
	}
	cout<<p;
}