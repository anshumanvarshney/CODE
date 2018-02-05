/*
Given an integer x and a positive number y, write a function that computes x^y under following conditions.
a) Time complexity of the function should be O(Log y)
b) Extra Space is O(1)
*/
//iterative
//power/2 and number^2 
#include<iostream>
#include<math.h>
using namespace std;

/* Iterative Function to calculate (x^y) in O(logy) */
int power(int x, unsigned int y)
{
    int res = 1;     // Initialize result
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y %2!=0)
            res = res*x;
 
        // n must be even now
        y = y/2; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}
 
// Driver program to test above functions
int main()
{
    int x = 3;
    unsigned int y = 5;
 
    printf("Power is %d", power(x, y));
 
    return 0;
}


//recursive

/*Space Complexity: O(1)
Algorithmic Paradigm: Divide and conquer.

Above function can be optimized to O(logn) by calculating power(x, y/2) only once and storing it.
*/
/* Function to calculate x raised to the power y in O(logn)*/
int power(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
/*
Time Complexity of optimized solution: O(logn)
Let us extend the pow function to work for negative y and float x.
*/
/* Extended version of power function that can work
 for float x and negative y*/
#include<stdio.h>
 
float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);       
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}  
 
/* Program to test function power */
int main()
{
    float x = 2;
    int y = -3;
    printf("%f", power(x, y));
    getchar();
    return 0;
}