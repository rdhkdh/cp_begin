#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;

        string s;
        cin>>s;

        int x=0,y=0;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='N') {y++;}
            if(s[i]=='E') {x++;}
            if(s[i]=='S') {y--;}
            if(s[i]=='W') {x--;}

            if(x==a && y==b) {break;}
        }

        //base cases
        if(x==a && y==b) 
        {
            cout<<"YES\n"; 
            continue;
        }
        if(x==0 && y==0) 
        {
            cout<<"NO"<<endl; 
            continue;
        }

        //diophantine eqn
        int deltaX = a - x;
        int deltaY = b - y;

        int g = __gcd(abs(x), abs(y));

        if(deltaX % g == 0 && deltaY % g == 0)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}