#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen( "fb_a22.txt", "w", stdout );
    //taking input
    int t;
    cin>>t;
    int x=t; //storing original value of t

    while(t--)
    {
        //taking input
        int r,c;
        cin>>r>>c;

        char mat[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>mat[i][j];
            }
        }

        //r and c are not 1
        if(r!=1 && c!=1)
        {
            cout<<"Case #"<<x-t<<": "<<"Possible"<<endl;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    cout<<"^";
                }
                cout<<endl;
            }
        }

        //atleast one of r or c is 1
        if(r==1 || c==1)
        {
            int flag=0; //assuming no tree present
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    if(mat[i][j]=='^') {cout<<"Case #"<<x-t<<": "<<"Impossible"<<endl; flag=1; break;} //tree present
                    else{flag=0;} //not a tree
                }
            }

            if(flag==0) //no tree present after the end of loop
            {
                cout<<"Case #"<<x-t<<": "<<"Possible"<<endl;
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        cout<<mat[i][j];
                    }
                    cout<<endl;
                }
            }
        }

    }//end of while loop
}