#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    string s;

    while(t--)
    {
        cin>>s;
        
        int n= s.length();

        map<int, pair<int,int>> mp; //starting index: <latest ending index with 0 sum,
        // count of pairs starting with 'starting index' and having 0 sum>

        int sum=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') {sum++;}
            if(s[i]=='0') {sum--;}

            if(sum==0) 
            {
                
            }
            
        }
    }
}