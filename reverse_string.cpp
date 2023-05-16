#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A;
    getline(cin,A,'\n');
    int n= A.length();

    string s,ans;
    for(int i=n-1;i>=0;i--)
    {
        if(int(A[i])!=32) //space
        {
            s= s+A[i];
        }
        else
        {
            if(!s.empty())
            {
                reverse(s.begin(),s.end());
                ans = ans+s;
                ans = ans+" ";
                s.clear();
            }
        }
    }
    reverse(s.begin(),s.end());
    ans = ans+s;

    cout<<ans<<endl;
}

