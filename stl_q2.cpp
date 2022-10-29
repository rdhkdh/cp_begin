#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    set<int> s;
    vector<int> v;

    for(int i=n-1;i>=0;i--)
    {
        if( binary_search(s.begin(),s.end(),arr[i]) ) {}
        else
        {
            s.insert(arr[i]);
            v.push_back(arr[i]);
        }
    }

    cout<<v.size()<<endl;
    for(int i=v.size()-1; i>=0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}