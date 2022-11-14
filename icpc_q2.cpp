#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		string str;
        cin>>str;
        int n=str.length();

        int index_m,index_u; 
        int flag_m=0,flag_u=0;  //assuming m,u not present

        //finding M
        for(int i=0;i<n;i++)
        {
            if(str[i]=='M') {index_m=i; flag_m=1; break;}
        }
        //finding U
        for(int i=index_m;i<n;i++)
        {
            if(str[i]=='U') {index_u=i; flag_u=1; break;}
        }

        if(flag_u==1 && flag_m==1)
        {
            if(index_m<index_u){cout<<"Yes"<<endl;}
            else{cout<<"No"<<endl;}
        }
        if(flag_u==0 || flag_m==0) {cout<<"No"<<endl;}

	}
}