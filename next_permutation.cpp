#include<bits/stdc++.h>
using namespace std;

void next_perm(vector<int>& v)
{
    int n=v.size();
    for(int i= n-1; i>=0; i--)
    {
        if(v[i]>v[i-1]) 
        {
            //find upperbound of v[i-1], it gives first element which is larger than val
            sort( v.begin()+i,v.end() );
            auto up_bnd = upper_bound(v.begin()+i,v.end(),v[i-1]); 
            //cout<<*up_bnd<<endl;
            swap( v[i-1],*up_bnd ); //if digits repeated then this creates problem
            sort( v.begin()+i,v.end() );
            break;
        }
    }
    for(auto i=v.begin(); i!=v.end(); i++)
    {
        cout<<char(*i); //remember to put char
    }
    cout<<endl;
}

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    sort(s.begin(),s.end());

    cout<<s<<endl;

    vector<int> v;
    v.clear();
    for(int i=0;i<n;i++) 
    { 
        v.push_back( int(s[i]) ); //ascii value 
    }
    vector<int> v_rev;
    v_rev=v;
    reverse(v_rev.begin(),v_rev.end()); // v in reverse

    int flag=0;
    while(flag==0)
    {
        next_perm(v);
        if(v==v_rev) {flag=1;}
    }
    
}