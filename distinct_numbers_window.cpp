#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++)
    {int x; cin>>x; A.push_back(x);}

    int b;
    cin>>b;



    vector<int> res; //size n-b+1
    // int n= A.size();
    int distinct_no[n]; distinct_no[0]=1;
    int count=0;
    map<int,int> m;
    
    for(int i=0;i<b;i++)
    {
        m[A[i]]++;
    }
    count=m.size();
    res.push_back(count);
    
    int i=1,j=b;
    while(j<n)
    {
        if(m[A[i-1]]==1) {count--;}
        //if(m[A[i-1]]==2) {count++;}
        m[A[i-1]]--;
        m[A[j]]++;
        if(m[A[j]]==1) {count++;}
        res.push_back(count);
        i++; j++;
    }
    
    for(auto u:res) {cout<<u<<" ";}
}
