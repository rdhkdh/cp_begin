#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("historian_hysteria_input.txt", "r", stdin);

    vector<int> a,b;
    int x,y;
    
    while(cin>>x>>y)
    {
        a.push_back(x);
        b.push_back(y);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    long long int dist=0;
    for(int i=0;i<a.size();i++)
    {
        dist += abs(a[i]-b[i]);
    }

    cout<<dist<<endl;
}