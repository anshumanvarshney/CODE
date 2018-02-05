#include <bits/stdc++.h>

using namespace std;

bool is_balanced(string str) {
    stack<char> s;
    int i=0,n;
	char x;
    n=str.length();
    for(int i=0;i<n;i++)
	{
		if(str[i]=='{'||str[i]=='['||str[i]=='(')
			s.push(str[i]);
        else 
        {
            if(s.empty()==true)
                return false;
            else
            {
                x=s.top();
                s.pop();
                if((x=='(' && str[i]!=')')||(x=='{' && str[i]!='}')||(x=='[' && str[i]!=']'))
		        {
	       	       return false;
		        }  
                
            }
        }
    }
	return ((s.empty())?true:false);  
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/*
int main()
{
	char a[10];
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		gets(a);  //warning gets function is dangerous use cin instead of it
		check(a);
	}
}

int main()
{
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		string a;
		cin>>a;
		check(a);
	}
}
*/