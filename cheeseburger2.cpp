#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cheeseburger_corollary_2_input.txt","r",stdin);
    freopen("cheeseburger_corollary_2_output.txt","w",stdout);

    int t;
    long long int a,b,c,s,d,k=-1;
    cin>>t;
    int og = t;

    while(t--)
    {
        cin>>a>>b>>c;

        k= -1;

        //s=0
        d = c/b;
        k = max(k, 2*d-1);

        //s=1
        if(a<=c)
        {
            d = (c-a)/b;
            k = max(k, 2*d+1);
        }
        

        //s=2
        if(2*a<=c)
        {
            d = (c-2*a)/b;
            k = max(k, 2*d+2);
        }
        

        //s=c/a
        s = c/a;
        d = (c - a*s)/b;
        k = max(k, min(s+2*d, 2*s+2*d-1));


        if(k==-1)
        {
            k=0;
        }
        cout<<"Case #"<<og-t<<": "<<k<<endl;
    }
}