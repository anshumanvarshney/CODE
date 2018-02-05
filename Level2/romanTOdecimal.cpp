/*
Converting Roman Numerals to Decimal lying between 1 to 3999
Given a Romal numeral, find its corresponding decimal value.

Example:

Input : IX
Output : 9

Input : XL
Output : 40

Input : MCMIV
Output :  1904
M is a thousand, CM is nine hundred 
and IV is four

Symbol Value

I - 1
V - 5
X - 10
L - 50
C - 100
D - 500
M - 1000

A number in Roman Numerals is a string of these symbols written in descending order
(e.g. M’s first, followed by D’s, etc.). However, in a few specific cases, to avoid four characters being 
repeated in succession (such as IIII or XXXX), subtractive notation is often used as follows:

I placed before V or X indicates one less, so four is IV (one less than 5) and 9 is IX (one less than 10).
X placed before L or C indicates ten less, so forty is XL (10 less than 50) and 90 is XC (ten less than a hundred).
C placed before D or M indicates a hundred less, so four hundred is CD (a hundred less than five hundred) and 
nine hundred is CM (a hundred less than a thousand).
*/

	

#include<bits/stdc++.h>
using namespace std;
/*
c solution
int romanToInt(char* A) {
    
    int a[256];
    a['X'] = 10;
    a['C'] = 100;
    a['M'] = 1000;
    a['V'] = 5;
    a['I'] = 1;
    a['D'] = 500;
    a['L'] = 50;
    int n = strlen(A);
    int ans = 0;int i;
    for(i = n-1;i>=0;i--)
    {  
		if( i==n-1 || a[A[i]]>=a[A[i+1]])
			ans+=a[A[i]];
		else
			ans-=a[A[i]];
    }
    return ans;

}

int main()
{
	char a[]="XV";
	cout<<romanToInt(a);
	return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
 
// This function returns value of a Roman symbol
int romanCharToInt(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}
 
// Returns decimal value of roman numaral
int romanToDecimal(string s)
{
   int num = 0;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            // Does lesser value precede higher value ? 
            if (i < (size - 1) && romanCharToInt(s[i]) < romanCharToInt(s[i + 1]))//it don't accept last element
			{
                num -= romanCharToInt(s[i]);//-(1 or 10 or 100)
            } 
			else
			{
                num += romanCharToInt(s[i]);
            }
        }
        return num;		
}
 
// Driver Program
int main()
{
    // Considering inputs given are valid
    string str ="IV";
    cout << "Integer form of Roman Numeral is "
         << romanToDecimal(str) << endl;
 
    return 0;
}