#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int n;
    string s;
    while(t--)
    {
        cin>>n;
        cin>>s;

        int i=0;
        int count_ones=0;
        int count_zeros=0;
        while(i<n)
        {
            if(s[i]=='1') 
            {
                count_ones++;
                i++;
            }
            else if(s[i]=='0')
            {
                count_zeros++;
                i++;
                while(s[i]=='0')
                {
                    i++;
                }

            }
            
        }

        if(count_ones>count_zeros) {cout<<"Yes\n";}
        else{cout<<"No\n";}
    }
}