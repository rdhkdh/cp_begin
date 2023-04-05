#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x1,y1,x2,y2;
        cin>>n>>x1>>y1>>x2>>y2;
        int lvl_start=0,lvl_end=0;
        if(x1<=n/2 && y1>n/2) { y1=n+1-y1;  }
        if(x1>n/2 && y1<=n/2) { x1=n+1-x1;  }
        if(x1>n/2 && y1>n/2) { y1=n+1-y1; x1=n+1-x1;}
        lvl_start=min(x1,y1);

        if(x2<=n/2 && y2>n/2) { y2=n+1-y2; }
        if(x2>n/2 && y2<=n/2) { x2=n+1-x2; }
        if(x2>n/2 && y2>n/2) { y2=n+1-y2; x2=n+1-x2; }
        lvl_end=min(x2,y2); 

        cout<<abs(lvl_end-lvl_start)<<endl;

    }
}