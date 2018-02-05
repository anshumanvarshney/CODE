/*
Print shortest path to print a string on screen
Given a screen containing alphabets from A-Z, we can go from one character to another characters using a remote. 
The remote contains left, right, top and bottom keys.

Find shortest possible path to type all characters of given string using the remote. 
Initial position is top left and all characters of input string should be printed in order.

Screen:
A B C D E
F G H I J
K L M N O
P Q R S T
U V W X Y
Z

For example,

Input: “GEEK”
Output: 
Move Down
Move Right
Press OK
Move Up
Move Right
Move Right
Move Right
Press OK
Press OK
Move Left
Move Left
Move Left
Move Left
Move Down
Move Down
Press OK
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
	    int i = 0,c=0;
    // start from charcater 'A' present at position (0, 0)
    int curX = 0, curY = 0;
    while (i < str.length())
    {
        // find cordinates of next character
        int nextX = (str[i] - 'A') / 5;
        int nextY = (str[i] - 'A') % 5;
 
        // Move Up if destination is above
        while (curX > nextX)
        {
            c++;
            curX--;
        }
 
        // Move Left if destination is to the left
        while (curY > nextY)
        {
            c++;
            curY--;
        }
 
        // Move down if destination is below
        while (curX < nextX)
        {
            c++;
            curX++;
        }
 
        // Move Right if destination is to the right
        while (curY < nextY)
        {
            c++;
            curY++;
        }
        // At this point, destination is reached
        c++;
        i++;
    }
        cout<<c<<"\n";//no. of times movement
    }
	return 0;
}