#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        map<string,int> mp;

        string arr[3][n];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
                mp[arr[i][j]]++; //counting no of occurences of string arr[i][j]
            }
        }

        
        for(int i=0;i<3;i++) //for every person
        {
            int points=0;
            for(int j=0;j<n;j++) //for every word he's written
            {
                if(mp[arr[i][j]]==1) {points+=3;}
                else if(mp[arr[i][j]]==2) {points+=1;}
            }
            cout<<points<<" ";
        }
        cout<<endl;

    }
    
}