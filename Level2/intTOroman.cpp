/*
Converting Decimal Number lying between 1 to 3999 to Roman Numerals
Given a number, find its corresponding Roman numeral.
Example:

Input : 9
Output : IX

Input : 40
Output : XL

Input :  1904
Output : MCMIV

value  symbol 
1		I
4		IV
5		V
9		IX
10		X
40		XL
50		L
90		XC
100		C
400		CD
500		D
900		CM
1000	M
*/


#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num)
{
	string M[] = {"", "M", "MM", "MMM"};//1000-3000 inc=1000
	string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};//100-900 inc=100
	string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};//10-90 inc=10	
	string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};//1-9  inc= 1
	return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
int main()
{
	int n;
	cin>>n;
	cout<<intToRoman(n);
}