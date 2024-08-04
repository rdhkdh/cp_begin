#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string S,x,y;
        cin>>S>>x>>y;

        if(S=="empty")
        {
            cout<<"Yes"<<endl;
            continue;
        }

        int l1 = x.length();
        int l2 = y.length();

        int count1=0, count2=0;
        for(int i=0;i<l1;i++)
        {
            if(x[i]=='1') {count1++;}
        }
        for(int i=0;i<l2;i++)
        {
            if(y[i]=='1') {count2++;}
        }

        if(count1==count2) //count of Ts
        {
            if(l1==l2)
            {
                cout<<"Yes"<<endl;
                continue;
            }
            else
            {
                cout<<"No"<<endl;
                continue;
            }
            
        }

        int Slen = S.length();
        int Tlen = ((l1-l2+count2-count1)*Slen)/(count2-count1);

        if(Tlen<0) 
        {
            cout<<"No"<<endl; 
            continue;
        }
        else if(Tlen==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        
        if(Tlen>=Slen)
        {
            cout<<"Yes"<<endl;
            continue;
        }


        //if T is substring of S
        string T = S.substr(0,Tlen);
        
        string X="",Y="";
        for(int i=0;i<l1;i++)
        {
            if(x[i]=='0')
            {
                X += S;
            }
            if(x[i]=='1')
            {
                X += T;
            }
        }
        for(int i=0;i<l2;i++)
        {
            if(y[i]=='0')
            {
                Y += S;
            }
            if(y[i]=='1')
            {
                Y += T;
            }
        }

        if(X==Y)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else
        {
            cout<<"No"<<endl;
            continue;
        }
    }
}