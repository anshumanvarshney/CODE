/*
Compare two Version numbers
A version number is a string which is used to identify unique states of a software product. A version number looks like a.b.c.d where a, b etc are number, so version number is a string in which numbers are separated by dots. These number generally represent hierarchy from major to minor (a is major and d is minor).
In this problem we are given two version numbers, we need to compare them and conclude which one is lates version number (that is which version number is smaller).

For example if
V1 = “1.0.31”
V2 = “1.0.27”
Then V2 version is latest (or smaller) 
because V2 < V1
*/

//  C/C++ program to compare two version number
#include <bits/stdc++.h>
using namespace std;
 
//  Method to compare two versions. Returns 1 if v2 is
// smaller, -1 if v1 is smaller, 0 if equal
int versionCompare(string v1, string v2)
{
    //  vnum stores each numeric part of version
    int vnum1 = 0, vnum2 = 0;
 
    //  loop untill both string are processed
    for (int i=0,j=0; (i<v1.length() || j<v2.length()); )
    {
        //  storing numeric part of version 1 in vnum1
        while (i < v1.length() && v1[i] != '.')
        {
            vnum1 = vnum1 * 10 + (v1[i] - '0');
            i++;
        }
 
        //  storing numeric part of version 2 in vnum2
        while (j < v2.length() && v2[j] != '.')
        {
            vnum2 = vnum2 * 10 + (v2[j] - '0');
            j++;
        }
 
        if (vnum1 > vnum2)
            return 1;
        if (vnum2 > vnum1)
            return -1;
 
        //  if equal, reset variables and go for next numeric
        // part
        vnum1 = vnum2 = 0;
        i++;
        j++;
    }
    return 0;
}
 
//  Driver method to check above comparison function
int main()
{
    string version1 = "1.0.3";
    string version2 = "1.0.7";
 
    if (versionCompare(version1, version2) < 0)
        cout << version1 << " is smaller\n";
    else if (versionCompare(version1, version2) > 0)
        cout << version2 << " is smaller\n";
    else
        cout << "Both version are equal\n";
    return 0;
}