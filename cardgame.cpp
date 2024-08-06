#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int a1,a2,b1,b2;
    cin>>t;

    while(t--)
    {
        cin>>a1>>a2>>b1>>b2;

        int count=0;

        int possibility[4][4] = {
            {a1,b1,a2,b2},
            {a1,b2,a2,b1},
            {a2,b1,a1,b2},
            {a2,b2,a1,b1}
        };

        for(int r=0;r<4;r++)
        {
            int sun=0,slav=0;
            if(possibility[r][0] > possibility[r][1]) { sun++; }
            else if(possibility[r][0] < possibility[r][1]) {slav++;}

            if(possibility[r][2] > possibility[r][3]) { sun++; }
            else if(possibility[r][2] < possibility[r][3]) {slav++;}

            if(sun>slav) {count++;}
        }
        cout<<count<<endl;
    }
}