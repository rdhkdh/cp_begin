#include<bits/stdc++.h>
using namespace std;
#define MAX 500100
pair<int,int> a[MAX];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i].first>>a[i].second;
            //scanf("%d%d", &a[i].first, &a[i].second);
        }
        sort(a,a+n,
        [&](const pair<int, int>& p1, const pair<int, int>& p2) 
        { return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first); }
        ); //sorting by decr order bi

        
        
    }
}