#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[4], int x)
{
    int temp[4];
    for(int i=0;i<4;i++)
    {
        temp[ (i+x)%4 ] = arr[i];
    }
    for(int i=0;i<4;i++) {arr[i]=temp[i];}
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[4];
        cin>>a[0]>>a[1];
        cin>>a[3]>>a[2];

        if(a[1]>a[0] && a[2]>a[3] && a[3]>a[0] && a[2]>a[1]) {cout<<"YES\n";}
        else{
            if(*min_element(a,a+4)==a[0]) {cout<<"NO\n";}
            else{
                int min_index= min_element(a,a+4)-a ; 
                rotate(a,4-min_index);
                (a[1]>a[0] && a[2]>a[3] && a[3]>a[0] && a[2]>a[1]) ? cout<<"YES\n" : cout<<"NO\n" ;
            }
        }
    }
    
}