#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    string s;
    cin>>t;

    while(t--)
    {
        cin>>n;
        cin>>s;

        int ca=0,cb=0,cc=0,cd=0,cq=0;
        for(int i=0;i<4*n;i++)
        {
            if(s[i]=='A') {ca++;}
            if(s[i]=='B') {cb++;}
            if(s[i]=='C') {cc++;}
            if(s[i]=='D') {cd++;}
            if(s[i]=='?') {cq++;}
        }

        int correct=0, wrong=0;
        if(ca>n)
        {
            correct += n;
            wrong += (ca-n);
        }
        else
        {
            correct += ca;
        }

        if(cb>n)
        {
            correct += n;
            wrong += (cb-n);
        }
        else
        {
            correct += cb;
        }

        if(cc>n)
        {
            correct += n;
            wrong += (cc-n);
        }
        else
        {
            correct += cc;
        }

        if(cd>n)
        {
            correct += n;
            wrong += (cd-n);
        }
        else
        {
            correct += cd;
        }

        //correct += cq;

        cout<<correct<<endl;
    }
}