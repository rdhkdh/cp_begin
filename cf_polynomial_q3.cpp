#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s; 

        int zero_count=0,one_count=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0') {zero_count++;}
            else {one_count++;}

            if(s[i]=='0')
            {
                cout<<one_count+1<<" ";
            }
            else{ cout<<zero_count+1<<" "; }
            
            
        }
        cout<<endl;
    }

}