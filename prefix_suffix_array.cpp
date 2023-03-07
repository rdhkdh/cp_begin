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

        string v[2*n-2];
        vector<int> filled(2*n-2,0); //size, initial value
        for(int i=0;i<2*n-2;i++) 
        {
            string s;
            cin>>s;
            int x= s.length();
            if(filled[2*x-2]==0) { v[2*x-2]=s; filled[2*x-2]=1; } //filling length wise
            else { v[2*x-1]=s; filled[2*x-1]=1; }
        }

        int flag=0;
        for(int l=1;l<=n-1;l++)
        {
            reverse(v[2*l-2].begin(),v[2*l-2].end());
            if( v[2*l-2].compare(v[2*l-1]) ==0 )
            {
                flag=0;
            }
            else{ flag=1; break;}
        }

        (flag==1)? cout<<"NO\n" : cout<<"YES\n";
    }
}