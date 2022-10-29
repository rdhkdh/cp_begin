#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int x=t;

    while(t--)
    {
        int m,n,p;
        cin>>m>>n>>p;

        int score[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>score[i][j];
            }
        }

        vector<int> day[n];
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                day[j].push_back(score[i][j]);
            }
        }

        int addnl_steps=0;
        for(int i=0;i<n;i++)
        {
            int max=*max_element( day[i].begin(),day[i].end() );
            if( max != day[i][p-1] ) { addnl_steps += ( max - day[i][p-1] ); }
        }

        cout<<"Case #"<<x-t<<": "<<addnl_steps<<endl;
    }
}