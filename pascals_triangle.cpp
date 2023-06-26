#include<bits/stdc++.h>
using namespace std;

vector<int> pascals_row(int k)
{
    vector<int> v;
    int c=1;
    for(int i=0;i<=k;i++)
    {
        v.push_back(c);
        c= c*(k-i)/(i+1);
    }

    return v;
}

int main()
{
    vector<int> res = pascals_row(5);
    for(auto u: res) {cout<<u<<" ";}
}