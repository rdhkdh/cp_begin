#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int flag1=0,flag2=0;

    while(t--)
    {
        string a,b;
        cin>>a>>b;

        int i=0;
        while(a[i]!='\0')
        {
            if(a[i]=='S') {flag1=1; break;}
            if(a[i]=='M') {flag1=2; break;}
            if(a[i]=='L') {flag1=3; break;}
            i++;
        }
        int j=0;
        while(b[j]!='\0')
        {
            if(b[j]=='S') {flag2=1; break;}
            if(b[j]=='M') {flag2=2; break;}
            if(b[j]=='L') {flag2=3; break;}
            j++;
        }

        if(flag1==1 && flag2==1) 
        {
            int c1=0,c2=0;
            int i=0;
            while(a[i]!='\0')
            {
                if(a[i]=='X') {c1++;}
                i++;
            }
            int j=0;
            while(b[j]!='\0')
            {
                if(b[j]=='X') {c2++;}
                j++;
            }
            if(c1>c2) {cout<<"<"<<endl;}
            else if(c1==c2) {cout<<"="<<endl;}
            else if(c1<c2) {cout<<">"<<endl;}

        }
        if(flag1==2 && flag2==2) 
        {
            cout<<"="<<endl;
        }
        if(flag1==3 && flag2==3) 
        {
            int c1=0,c2=0;
            int i=0;
            while(a[i]!='\0')
            {
                if(a[i]=='X') {c1++;}
                i++;
            }
            int j=0;
            while(b[j]!='\0')
            {
                if(b[j]=='X') {c2++;}
                j++;
            }
            if(c1>c2) {cout<<">"<<endl;}
            else if(c1==c2) {cout<<"="<<endl;}
            else if(c1<c2) {cout<<"<"<<endl;}
        }

        if(flag1==1 && flag2==2) {cout<<"<"<<endl;}
        if(flag1==2 && flag2==1) {cout<<">"<<endl;}

        if(flag1==1 && flag2==3) {cout<<"<"<<endl;}
        if(flag1==3 && flag2==1) {cout<<">"<<endl;}

        if(flag1==2 && flag2==3) {cout<<"<"<<endl;}
        if(flag1==3 && flag2==2) {cout<<">"<<endl;}

    }
}