#include<bits/stdc++.h>
using namespace std;

long long int x;
int n;

int solve(int a[], int b[], int c[], int& la, int& ra, int& lb, int& rb, int& lc, int& rc)
{
    int flag=0;
    long long int sum = 0;
    la=0; rc=n-1;

    for(int i=la;i<n;i++)
    {
        sum += a[i];
        if(sum>=x)
        {
            ra = i;
            break;
        }
    }
    lb=ra+1;
    sum=0;
    for(int i=lb;i<n;i++)
    {
        sum += b[i];
        if(sum>=x)
        {
            rb = i;
            break;
        }
    }
    lc=rb+1;
    sum=0;
    for(int i=lc;i<n;i++)
    {
        sum += c[i];
        if(sum>=x)
        {
            flag=1;
            break;
        }
    }

    la++; ra++;
    lb++; rb++;
    lc++; rc++;


    if(flag==1) {return 1;} //possible to partition

    return 0; //not possible to partition
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int a[n],b[n],c[n];

        long long int tot=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            tot += a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }

        x = ceil(tot/3);

        int la=0,ra=0,lb=0,rb=0,lc=0,rc=0;
        
        int f1 = solve(a,b,c,la,ra,lb,rb,lc,rc); //abc
        if(f1==1)
        {
            cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
            continue;
        }
        f1 = solve(a,c,b,la,ra,lc,rc,lb,rb); //acb
        if(f1==1)
        {
            cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
            continue;
        }
        f1= solve(b,a,c,lb,rb,la,ra,lc,rc); //bac
        if(f1==1)
        {
            cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
            continue;
        }
        f1 = solve(b,c,a,lb,rb,lc,rc,la,ra); //bca
        if(f1==1)
        {
            cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
            continue;
        }
        f1 = solve(c,a,b,lc,rc,la,ra,lb,rb); //cab
        if(f1==1)
        {
            cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
            continue;
        }
        f1 = solve(c,b,a,lc,rc,lb,rb,la,ra); //cba
        if(f1==1)
        {
            cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<endl;
            continue;
        }
        
        cout<<-1<<endl;
    }

}