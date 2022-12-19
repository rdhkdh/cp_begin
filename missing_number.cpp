#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x[n-1];
    for(int i=0;i<n-1;i++) {cin>>x[i];}

    sort(x,x+n-1);

    int current=1;
    for(int i=0;i<n-1;i++)
    {
        if(x[i]==current) {current++;}
        else{break;}
    }
    cout<<current;
    // vector<int> v;
    // for(int i=1;i<=n;i++) { v.push_back(i); }
    
    // for(int i=0; i<n-1; i++)
    // {
    //     v.erase(v.begin()+x[i]-1);
    // }
    // cout<<v[0];

}