#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x;
    cin>>n>>k>>x;

    int temp;
    for(int i=0;i<n;i++) 
    { 
        cin>>temp; 
        cout<<temp<<" ";

        if(i==k-1)
        {
            cout<<x<<" ";
        }
    }
    


    return 0;
}