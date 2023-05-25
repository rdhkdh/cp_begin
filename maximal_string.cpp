#include<bits/stdc++.h>
using namespace std;

int main()
{
    string A; int B;
    cin>>A>>B;
    string max_str=A;

    int k=B;
    string str= A;
    while(k>0)
    {
        int n=str.length(),flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(str[i],str[j]);
                if(stoi(max_str)<stoi(str)) {max_str = str; k--; flag=1; break;}
                
                swap(str[i],str[j]); // if not max 
            }
            if(flag==1) {break;}
        }
    }
    
    
    cout<<max_str<<endl;
}



