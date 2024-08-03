#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        char s[2][n];

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> s[i][j];
            }
        }

        //0 regions
        int flag0=1;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[i][j]=='.')
                {
                    flag0=0;
                    break;
                }
            }
        }
        if(flag0==1)
        {
            cout<<0<<endl;
            continue;
        }
        

        //1 region
        int count=0;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[i][j]=='.')
                {
                    // if(j==0)
                    // {
                    //     if(s[1-i][j+1]=='x' &&
                    //     s[1-i][j]=='.' &&
                    //     s[i][j+1]=='.')
                    //     { count++;}
                    // }
                    // else if(j==n-1)
                    // {
                    //     if(s[1-i][j-1]=='x' && 
                    //     s[1-i][j]=='.' &&
                    //     s[i][j-1]=='.' )
                    //     { count++;}
                    // }
                    
                        if(s[1-i][j-1]=='x' && 
                        s[1-i][j+1]=='x' &&
                        s[1-i][j]=='.' &&
                        s[i][j-1]=='.' &&
                        s[i][j+1]=='.')
                        { count++;}
                    
                }
            }
        }

        cout<<count<<endl;
    }

}