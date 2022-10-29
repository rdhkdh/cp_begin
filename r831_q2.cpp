#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        long long int a[n],b[n],b_sum=0;

        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
            if(b[i]>a[i]) { swap(a[i],b[i]); }
            b_sum+=b[i];
        }

        cout<< (2*b_sum)+( 2*( *max_element(a,a+n) ) )<<endl;
    }
}
