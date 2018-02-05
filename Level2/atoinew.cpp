/*
Atoi
convert string to number

Example :

Input : "9 2704"
Output : 9
test cases

9 d45
9

+7
7
   7
7

7 86 d45
7

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
*/

int Solution::atoi(const string &str) {

    int sign = 1, n = 0, i = 0;
    while (str[i] == ' ')i++;
    if (str[i] == '-' || str[i] == '+') 
         sign = (str[i++] == '-') ? -1 : 1;

    while (str[i] >= '0' && str[i] <= '9')
    {
      if (n >  INT_MAX / 10 || (n == INT_MAX / 10))
      {
        if (sign == 1) return INT_MAX;
        else return INT_MIN;
      }
      n  = 10 * n + (str[i++] - '0');
    }
    return n * sign;
  }
    