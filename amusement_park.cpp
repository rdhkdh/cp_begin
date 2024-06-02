#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int total_people=0, count=1;
    for(int i=0;i<n;i++)
    {
        if(total_people+a[i]<=k)
        {
            total_people += a[i];
        }
        else
        {
            count++;
            total_people = a[i];
        }
    }
    cout<<count<<endl;
}