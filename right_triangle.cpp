#include<bits/stdc++.h>
using namespace std;

int main()
{
    int xa,ya,xb,yb,xc,yc;
    cin>>xa>>ya;
    cin>>xb>>yb;
    cin>>xc>>yc;

    int s1 = ((xa-xb)*(xa-xb)) + ((ya-yb)*(ya-yb)); //a square
    int s2 = ((xa-xc)*(xa-xc)) + ((ya-yc)*(ya-yc));
    int s3 = ((xc-xb)*(xc-xb)) + ((yc-yb)*(yc-yb));


    if(s3>=s2 && s3>=s1)
    {
        if(s3 == s1+s2) {cout<<"Yes\n"; return 0;}
        else{cout<<"No\n"; return 0;}
    }
    else if(s2>=s3 && s2>=s1)
    {
        if(s2 == s1+s3) {cout<<"Yes\n"; return 0;}
        else{cout<<"No\n"; return 0;}
    }
    else if(s1>=s2 && s1>=s3)
    {
        if(s1 == s3+s2) {cout<<"Yes\n"; return 0;}
        else{cout<<"No\n"; return 0;}
    }

}