//TIME LIMIT EXCEEDED for large test cases, because you're starting with original string everytime in k-iteration loop?

#include<bits/stdc++.h>
using namespace std;
#define int long long


int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;

    string og_str,str; //orignal string, optimized string
    cin>>og_str;
    str=og_str; //do changes only in str, keep og_str unchanged

    for(int k=1;k<=n;k++)
    {

        if(n%2==0) //even
        {
            int y=(n/2)-1; //1 right shift for dividing by 2
            int count=0;
            for(int i=0;i<=y;i++)
            {
                
                if(og_str[i]=='L') {str[i]='R'; count++;}
                if(count==k) {break;}
                if(og_str[n-1-i]=='R') {str[n-1-i]='L'; count++;}
                if(count==k) {break;}
            }//got the optimized string
        }

        else if(n%2==1 && n>1) //odd
        {
            int z=(n-3)/2;
            int count=0;
            for(int i=0;i<=z;i++)
            {
                if(og_str[i]=='L') {str[i]='R'; count++;}
                if(count==k) {break;}
                if(og_str[n-1-i]=='R') {str[n-1-i]='L'; count++;}
                if(count==k) {break;}
            }//got the optimized string
        }

        //now that we have optimized string, we'll total the sum of the line
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='R') {sum+=(n-1-i);}
            else if(str[i]=='L') {sum+=i;}
        }
        cout<<sum<<" ";

    }//end of k iterations
    cout<<endl;

    }//end of while
}//end of main


