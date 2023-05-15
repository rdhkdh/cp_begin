#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A;
    getline(cin, A, '\n');

    int n= A.length();
    vector<char> v;
    
    for(int i=0;i<n;i++)
    {
        if(int(A[i])<=90 && int(A[i])>=65) //capital letters
        {
            A[i] = char(int(A[i])+32);
            v.push_back(A[i]);
        }  
        else if(int(A[i])<=122 && int(A[i])>=97) //small letters
        {
            v.push_back(A[i]);
        }
        else if(int(A[i])<=57 && int(A[i])>=48) //numbers
        {
            v.push_back(A[i]);
        }
    }
    
    int i=0,j=v.size()-1,flag=1;
    while(i<=j)
    {
        if( int(v[i])==int(v[j]) )
        {
            flag=1;
            i++;j--; 
        }
        else{flag=0; break;}
    }
    
    cout<<flag<<endl;
}