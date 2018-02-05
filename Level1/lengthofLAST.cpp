/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.
*/

int Solution::lengthOfLastWord(const string &s) 
{
    string res,ans;
    int i,c=0;
    if(s.length()==0)
        return 0;
    for(i=0;i<s.length();i++)
    {
        if(s[i]==' ')
            res="";
        else
        {
            res+=s[i];
            ans=res;
        }
    }
    
    return ans.length();
}
/*
test cases
"hello world"=5
"hello world  "=5
"d"=1
*/