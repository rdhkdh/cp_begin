#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;

        if(c!='g')
        {
            s=s+s;

            int diff=0;
            int max=diff;
            for(int i=0;i<n;i++)
            {
                if(s[i]==c)
                {
                    for(int j=i+1;j<2*n;j++)
                    {
                        if(s[j]=='g') 
                        {
                            diff=j-i; 
                            if(diff>max) {max=diff;}
                            break;
                        }
                        
                    }
                }
            }

            cout<<max<<endl;
        }

        if(c=='g') {cout<<0<<endl;}

    }
}