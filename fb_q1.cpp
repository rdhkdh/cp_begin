#include<bits/stdc++.h>
using namespace std;

int main()
{
    //test cases
    int t,x;
    cin>>t;
    x=t; //storing original value of t

    while(t--)
    {
        //taking input
        int n,k;
        cin>>n>>k;

        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        if(n>2*k) {cout<<"Case #"<<x-t<<": "<<"NO"<<endl;} //if n greater than 2k, invalid case
        else //if n<=2k
        {
            sort(arr,arr+n);
            int count=0; //frequency of a number
            int flag=1; //initially assuming numbers with freq above 2 don't exist in array
            for(int i=0;i<n-1;i++) //n-1 because we're accessing i+1
            {
                if(arr[i]!=arr[i+1]) {count=0;}
                else{count++;}
                if(count==2) {flag=0; break;} //found number with freq greater than 2
                else if(count<2) {flag=1;}
            }
            if(flag==0) {cout<<"Case #"<<x-t<<": "<<"NO"<<endl;}
            else{cout<<"Case #"<<x-t<<": "<<"YES"<<endl;} //flag=1, all numbers with freq=0 or 1

        }
    }
}
