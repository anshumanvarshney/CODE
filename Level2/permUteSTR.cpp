/*
permutation of given string
Write a program to print all permutations of a given string
A permutation, also called an “arrangement number” or “order,” is a rearrangement 
of the elements of an ordered list S into a one-to-one correspondence with S itself.
 A string of length n has n! permutation.


Below are the permutations of string ABC.
ABC ACB BAC BCA CBA CAB
*/
l=0;r=n-1
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%sn", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

//or using STL

void permute(string str)
{
    // Sort the string in lexicographically
    // ascennding order
    sort(str.begin(), str.end());
 
    // Keep printing next permutation while there
    // is next permutation
    do {
       cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}