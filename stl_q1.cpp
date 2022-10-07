#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<long int> v1;
    long int x;
    for(int i=0;i<n;i++) 
    {
        cin>>x;
        v1.push_back(x);
    }

    sort(v1.begin(),v1.end());
    int count=0;
    for(int i=0; i<(v1.size()-1); i++) 
    {
        if(v1[i]!=v1[i+1])
        {
            count++;
        }
    }
    count=count+1;//for counting the last element.
    cout<<count<<endl;
}