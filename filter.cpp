#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    vector<int> even;
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        if(a[i]%2==0) {even.push_back(a[i]);}
    } 
    for (auto u: even) {cout<<u<<" ";}    
    
    
}