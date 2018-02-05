/*
Input Format
The first line is the number of test cases, followed by a blank line.
Each test case of your program consists of a list of the species of every tree observed by the satellite; 
one tree per line. No species name exceeds 30 characters. There are no more than 10,000 species and 
no more than 1,000,000 trees.
There is a blank line between each consecutive test cases.

Output Format
For each test case print the name of each species represented in the population, in alphabetical order,
 followed by the percentage of the population it represents, to 4 decimal places. 
 Print a blank line between 2 consecutive test cases

Sample Input 0

1

Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow
Sample Output 0

Ash 13.7931
Aspen 3.4483
Basswood 3.4483
Beech 3.4483
Black Walnut 3.4483
Cherry 3.4483
Cottonwood 3.4483
Cypress 3.4483
Gum 3.4483
Hackberry 3.4483
Hard Maple 3.4483
Hickory 3.4483
Pecan 3.4483
Poplan 3.4483
Red Alder 3.4483
Red Elm 3.4483
Red Oak 6.8966
Sassafras 3.4483
Soft Maple 3.4483
Sycamore 3.4483
White Oak 10.3448
Willow 3.4483
Yellow Birch 3.4483
*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    
    int n;
    cin>>n;
    getline(cin, s);//for input
    getline(cin,s);//for new line
    while(n--)
    {
        map<string,float> m;
        long long int c=0;
        c++;
        for(c=0;getline(cin,s);c++)
        {
          
            if(s.length()==0)
                break;
            m[s]++;
        }
        map<string,float> :: iterator i;
        for(i=m.begin();i!=m.end();i++)
        {
            cout<<i->first<<" ";
            cout<<fixed<<setprecision(4)<<((i->second)*100)/c<<"\n";
         }
        cout<<"\n";
     }
    return 0;
}
