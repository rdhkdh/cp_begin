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

        char arr[2][n];
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }

        //converting all blue cells to green
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]=='B') {arr[i][j]='G';}
            }
        }

        //now comparing the 2 arrays

        int flag=0; //intially assuming the arrays are not same
        for(int i=0;i<n;i++)
        {
            if(arr[0][i]==arr[1][i]) {flag=1;}
            else{flag=0; break;}
        }
        if(flag==0) {cout<<"NO"<<endl;} //arrays not same
        else{cout<<"YES"<<endl;} // flag=1, all elem same
    }
}