#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int xc,yc,k;
        cin>>xc>>yc>>k;

        int x[k],y[k];

        int xsum=xc*k;
        int ysum=yc*k;

        for(int i=0;i<k-1;i++) //k-1 elems = 1,2,3..k-1
        {
            x[i] = i+1;
            y[i] = i+1;
        }

        int r = xsum - (((k-1)*k)/2);
        int s = ysum - (((k-1)*k)/2);

        if(r<=k-1)
        {
            x[0]--;
            r++;
            x[k-1] = r;
        }
        else
        {
            x[k-1] = r;
        }

        if(s<=k-1)
        {
            y[0]--;
            s++;
            y[k-1] = s;
        }
        else
        {
            y[k-1] = s;
        }


        for(int i=0;i<k;i++)
        {
            cout<<x[i]<<" "<<y[i]<<endl;
        }
    }
    

}