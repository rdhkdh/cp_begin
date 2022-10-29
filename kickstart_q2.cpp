#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int t;
    cin>>t;
    int t1=t;

    while(t--)
    {
        int rs,rh,n,m;
        cin>>rs>>rh;
        cin>>n;

        int red[n];
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            red[i]=(x*x)+(y*y); //dist square
        }

        cin>>m;

        int yellow[m];
        for(int i=0;i<m;i++)
        {
            int z,w;
            cin>>z>>w;
            yellow[i]=(z*z)+(w*w); //dist square
        }

        int min_red=*min_element(red,red+n);
        int min_yellow;
        if(m>0)
        { min_yellow = *min_element(yellow,yellow+m); }
        if(m==0) { min_yellow = 800000000; }

        int redpt=0,yellowpt=0;
        if(min_red<min_yellow)
        {
            for(int i=0;i<n;i++)
            {
                if( red[i] <= ((rs+rh)*(rs+rh)) && red[i]<min_yellow )
                {
                    redpt++;
                }
            }
        }

        if(min_yellow<min_red)
        {
            for(int i=0;i<m;i++)
            {
                if( yellow[i] <= ((rs+rh)*(rs+rh)) && yellow[i]<min_red )
                {
                    yellowpt++;
                }
            }
        }

        cout<<"Case #"<<t1-t<<": "<<redpt<<" "<<yellowpt<<endl;

    }   
}