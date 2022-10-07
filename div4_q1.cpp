#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        //taking input
        int n;
        cin>>n;

        char arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        if(n!=5) {cout<<"NO"<<endl; continue;} //shift to next value of t
        else //if n=5
        {
            int flag=1; //initially assuming correct characters are there
            for(int i=0;i<n;i++)
            {
                if(arr[i]== 'T' || arr[i]=='i' || arr[i]=='m'|| arr[i]=='u' || arr[i]=='r') {flag=1;}
                else{flag=0; break;}
            }
            if(flag==0) {cout<<"NO"<<endl; continue;} //shift to next value of t

            //checking for repeated characters, if flag=1
            
            sort(arr,arr+n); //will arrange chars in asc. order

            int repeated=0; //initially assuming no repeated chars
            for(int i=0;i<n-1;i++)
            {
                if(arr[i]==arr[i+1]) {repeated=1; break;}
                else{repeated=0;}
            }
            if(repeated==1) {cout<<"NO"<<endl; }
            else if(repeated==0 && flag==1) {cout<<"YES"<<endl;} //no repeated, and correct chars

        }
    }
}