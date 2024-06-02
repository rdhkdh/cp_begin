#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    cin>>t;

    while(t--)
    {
        cin>>s;

        int n= s.length();
        int arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = int(s[i])-int('0');
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        // string s1 = s;
        // sort(s1.begin(),s1.end());
        // if(s1==s) 
        // {
        //     cout<<"1"<<endl; 
        //     continue;
        // }

        int pieces=0;

        int i=0, flag0=0, flag1=0;
        while(i<n-1)
        {
            
            // while(s[i]=='0')
            // {
            //     flag0=1;
            //     i++;
            // }
            // if(flag0==1)
            // {
            //     pieces++;
            //     flag0=0;
            // }
            
            // while(s[i]=='1')
            // {
            //     flag1=1;
            //     i++;
            // }
            // if(flag1==1)
            // {
            //     pieces++;
            //     flag1=0;
            // }

            while(arr[i]<=arr[i+1])
            {
                i++;
            }
            pieces++;
        }

        // if(pieces>1)
        // {
        //     cout<<pieces-1<<endl;
        // }
        // else{
        //     cout<<pieces<<endl;
        // }
        cout<<pieces<<endl;
    }

}