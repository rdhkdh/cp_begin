#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    string s;
    

    while(t--)
    {
        map<char,int> mp;
        cin>>s;
        int n= s.length();

        if(n==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                mp[s[i]]++;
            }

            if(mp.size()==1)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES"<<endl;

                int arr[n];
                for(int i=0;i<n;i++)
                {
                    arr[i] = int(s[i]);
                }
    
                next_permutation(arr,arr+n);

                for(int i=0;i<n;i++)
                {
                    cout<<char(arr[i]);
                }
                cout<<endl;
            }
        }
    }
}