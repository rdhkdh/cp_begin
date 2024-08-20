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
        int a[n];
        for(int i=0;i<n;i++) {cin>>a[i];}

        long long int prefixsum[n+1];
        prefixsum[0]=0;
        for(int i=1;i<=n;i++)
        {
            prefixsum[i] = prefixsum[i-1]+a[i-1];
        }

        string s;
        cin>>s;

        vector<int> L_index;
        vector<int> R_index;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L') {L_index.push_back(i);}
            if(s[i]=='R') {R_index.push_back(i);}
        }

        int nL = L_index.size();
        int nR = n-nL;

        int i=0,j=nR-1;
        long long int ans=0;
        while(i<nL && j>=0)
        {
            if(L_index[i]<R_index[j]) 
            {
                ans += (prefixsum[R_index[j]+1] - prefixsum[L_index[i]]);
                i++;
                j--;
            }
            else{break;}
        }
        cout<<ans<<endl;
    }
}