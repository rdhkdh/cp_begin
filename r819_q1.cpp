#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,max;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) {cin>>a[i];}        
        
        int* p=max_element(a,a+n);
        int* q=min_element(a,a+n);
        if(a[n-1]-*q > *p-a[0]) {max=a[n-1]-*q;}
        else{max= *p-a[0];}

        if(*p != a[n-1]) 
        {
            int x=*p;
            p++;
            int y=*p;
            int z=x-y;
        
            if(z>max) {max=z;}
        }
        cout<<max<<endl;
    }
}


