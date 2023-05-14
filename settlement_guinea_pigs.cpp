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

        int known=0,unknown=0,aviaries_needed=0;
        for(int i=1;i<=n;i++) 
        {
            int x;
            cin>>x; 
            if(x==1) { unknown++; }
            else{ known+=unknown; unknown=0;} //x=2
            aviaries_needed=max( aviaries_needed, unknown+( known ? known/2+1 : 0) );
        }
        cout<<aviaries_needed<<endl;

    }
}