
int Solution::strStr(const string &haystack, const string &needle) {


    int n=haystack.size();
    int z=needle.size();
    if(n==0 || z==0)
        return -1;
    int i,j;
    for(i=0;i<n;i++)
	{
        if(haystack[i]==needle[0])
		{
            j=0;
            while(j<z && haystack[j+i]==needle[j]) j++;
            if(j==z)
                return i;
        }
    }
    return -1;
}
