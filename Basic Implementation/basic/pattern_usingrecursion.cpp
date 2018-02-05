/*
1
12
123
1234
12345
*/

#include <bits/stdc++.h>
using namespace std;

void fun1(int n)
{
   int i = 0;  
   if (n > 1)//because we don't want recursive call for 1 
     fun1(n-1);
   for (i = 1; i <= n; i++)
     printf("%d",i);
  printf("\n");
}


int main()
{
  int n;
  scanf("%d",&n);
  fun1(n);

	return 0;
}