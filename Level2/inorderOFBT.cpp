/*
You are given a binary tree in the form of an array.
Binary tree is represented as an array in the following format :

the value of a node is stored in a[node].
the value for the left child of the node is stored in a[node + node]
the value for the right child of the node is stored in a[node + node + 1]
for any node, if a[node] is 0 it means the node is null
Given the array representation of a binary tree, print its Inorder Traversal

Sample Input 0
15
1 2 3 4 0 5 6 0 0 0 0 0 0 7 8

Sample Output 0
4 2 1 5 3 7 6 8
*/
#include<bits/stdc++.h>
using namespace std;

int a[1000000];
void printinorder(int node)
{
    if (a[node] == 0) return;
    printinorder(node + node);
    cout << a[node] << " ";
    printinorder(node + node + 1);
}
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
     long long int n,i,c;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    printinorder(1);
    return 0;
}