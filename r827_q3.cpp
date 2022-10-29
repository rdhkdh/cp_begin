#include<bits/stdc++.h>
using namespace std;

int colour_check(char arr[], int n) // 1 if same colour throughout
{
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]=='R')
        {
            if(arr[i]==arr[i+1]) {flag=1;}
            else{ flag=0; break;}
        }
    }

    return flag;

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        char mat[8][8];

        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cin>>mat[i][j];
            }
        }

        int index=-1;
        for(int i=0;i<8;i++)
        {  
            if( colour_check(mat[i],8) ) {index=i; break;}
        }
        if(index>-1) {cout<<"R"<<endl;}
        //if(index>-1 && mat[index][0]=='B') {cout<<"B"<<endl;}


        int flag=0,col_index=-1,i=0;
        for(i=0;i<8;i++)
        {
            for(int k=0;k<7;k++)
            {
                if(mat[k][i]!='.')
                {
                    if( mat[k][i]==mat[k+1][i] ) {flag=1;}
                    else {flag=0; break;}
                }
                
            }
            if(flag==1) {col_index=i; break;}

        }
        //if(col_index>-1 && mat[0][col_index]=='R') {cout<<"R"<<endl;}
        if(col_index>-1) {cout<<"B"<<endl;}
        
    }
}