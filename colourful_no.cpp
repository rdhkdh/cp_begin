#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A;
    cin>>A;
    string s= to_string(A);
    int n=s.length();
    
    vector<int> products;
    for(int i=0;i<n;i++)
    {
        string temp=""; temp+=s[i];
        if(find(products.begin(),products.end(),int(s[i])-48)!=products.end()) {cout<<0; return 0;}
        else{products.push_back(int(s[i])-48);}
        for(int j=i+1;j<n;j++)
        {
            temp+=s[j];
            int x= stoi(temp);
            int pdt=1;
            while(x>0)
            {
                pdt= pdt*(x%10);
                x=x/10;
            }
            if(find(products.begin(),products.end(),pdt)!=products.end()) {cout<<0; return 0;}
            else{products.push_back(pdt);}
        }
    }
    
    cout<<1; return 0;

}