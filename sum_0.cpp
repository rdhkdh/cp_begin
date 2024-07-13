#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int l[n],r[n],x[n];
    long long int sum_l=0;

    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        sum_l += l[i];
        x[i] = l[i];
    }

    if(sum_l>0) {cout<<"No\n"; return 0;}

    for(int i=0;i<n;i++)
    {
        long long int diff = r[i]-l[i];
        long long int temp = sum_l+diff;

        if(temp>=0)
        {
            x[i] -= sum_l;
            sum_l = 0;
            break;
        }
        else
        {
            x[i]=r[i];
            sum_l += diff;
        }
    }

    if(sum_l!=0) {cout<<"No\n"; return 0;}

    cout<<"Yes\n";
    for(int i=0;i<n;i++) 
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;

    return 0;
}