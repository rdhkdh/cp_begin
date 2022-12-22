#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int y;
    vector<long long int> x;
    for(int i=0;i<n;i++) 
    {
        cin>>y;
        x.push_back(y);
    }
    sort(x.begin(),x.end());

    x.erase(unique(x.begin(),x.end()),x.end()); //remove duplicates
    cout<<x.size();
}