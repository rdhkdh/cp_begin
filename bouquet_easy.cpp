#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    long long int m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++) {cin>>arr[i];}

        sort(arr,arr+n);
        
        int count_a=0, count_b=0, flag_a=0,flag_b=0, greater_flag=0;
        int a,b;
        long long int max_val= -1;

        int i=0;
        for(i=0;i<n;i++)
        {
            if(i==0) 
            { 
                a = arr[0];
                flag_a=1;
                count_a++; 
                continue;
            }

            
            if(arr[i]==arr[i-1] && flag_a==1) {count_a++;}
            
            if(arr[i]==arr[i-1] && flag_b==1) {count_b++;}

            if(arr[i]!=arr[i-1] && flag_b==0) {b = arr[i]; flag_b=1; count_b++; continue;}

            if(arr[i]!=arr[i-1] && flag_b==1)
            {
                if(b-a==1)
                {
                    long long int x = (count_a*a) + (count_b*b);
                    if(x>=m) {greater_flag=1; break;}
                    else
                    {
                        max_val = max(x,max_val);
                        count_a = count_b;
                        count_b=0;
                        a=b;
                        flag_a=1;
                        flag_b=0;
                    }
                }
                else
                {
                    count_a = count_b;
                    count_b=0;
                    a=b;
                    flag_a=1;
                    flag_b=0;
                }
                
            } 
               
            
        } //end of for loop

        if(i==n && b-a==1)
        {
            long long int x = (count_a*a) + (count_b*b);
            if(x>=m) {greater_flag=1;}
            else
            {
                max_val = max(x,max_val); 
            }
            
        }

        if(greater_flag==1) {cout<<m<<endl; continue;}
        else
        {
            if(max_val==-1) {cout<<arr[n-1]<<endl;} //no consecutive
            else {cout<<max_val<<endl;}
        }
    } //end of while loop

    return 0;
}