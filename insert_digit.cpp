#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        string s;
        cin>>s;

        int index=n;
        for(int i=0;i<n;i++)
        {
            if( int(s[i])-48<d ) {index=i; break;}
        }

        string s1,s2,s3;
        if(index<n)
        {
            s1= s.substr(0,index);
            s2= s.substr(index,n-index);
            s3= s1+char(d+48)+s2;
        }
        else{
            s3=s+char(d+48);
        }

        cout<<s3<<endl;
    }
}