#include<bits/stdc++.h>
using namespace std;

vector<double> get_intersection(double s1, double e1, double s2, double e2)
{
    //complete intersection
    if(s1<=s2 && e2<=e1)
    {
        return {s2,e2};
    }
    if(s2<=s1 && e1<=e2)
    {
        return {s1,e1};
    }

    //no intersection
    if(s1>e2 || e1<s2)
    {
        return {};
    }

    //partial intersection
    if(s1<=e2 && e2<=e1)
    {
        return {s1,e2};
    }
    if(s2<=e1 && e1<=e2)
    {
        return {s2,e1};
    }

}

int main()
{

    freopen("subsonic_subway_input.txt", "r", stdin);
    freopen("subsonic_subway_output.txt", "w", stdout);

    int t, n;
    cin>>t;
    int og = t;

    while(t--)
    {
        cin>>n;
        int a[n],b[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
        }

        double ma = double(a[0]); // a[i]/(i+1)
        double mb = double(b[0]); // b[i]/(i+1)
        vector<double> res;

        int flag = 0;
        for(int i=1;i<n;i++)
        {
            double ma2 = double(a[i])/double(i+1);
            double mb2 = double(b[i])/double(i+1);

            res = get_intersection(ma, mb, ma2, mb2);

            if(res.size()==0) {flag=1; break;}
            else{
                ma = res[0];
                mb = res[1];
            }
        }

        if(flag==1) {cout<<"Case #"<<og-t<<": "<<-1<<endl;}
        else
        {
            //ma = double(1)/ma;
            mb = double(1)/mb;
            cout<<"Case #"<<og-t<<": "<<mb<<endl;
        }
    }
}