#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,a,b,c,d;
    cin>>t;

    while(t--)
    {
        cin>>a>>b>>c>>d;
        a%=12; b%=12; c%=12; d%=12;

        if(a>b)
        {
            swap(a,b);
        }
        if(c>d)
        {
            swap(c,d);
        }

        
        // a<b and c<d
        set<int> set1,set2;

        int i= a+1; i%=12;
        while(i!=b)
        {
            set1.insert(i);

            i++;
            i%=12;
        }

        int j= b+1; j%=12;
        while(j!=a)
        {
            set2.insert(j);

            j++;
            j%=12;
        }

        if(
            (set1.find(c)!=set1.end() && set1.find(d)!=set1.end()) || 
            (set2.find(c)!=set2.end() && set2.find(d)!=set2.end()) 
        ) {
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}