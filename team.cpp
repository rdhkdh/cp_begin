#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    int n;
    cin>>n;
    int x,y,z,zero_count,prob_count=0;
    for(int i=0;i<n;i++)
    {
        zero_count=0;
        cin>>x>>y>>z;
        if(x==0) {zero_count++;}
        if(y==0) {zero_count++;}
        if(z==0) {zero_count++;}
        if(zero_count<=1) {prob_count++;}
    }
    cout<<prob_count<<endl;
 }