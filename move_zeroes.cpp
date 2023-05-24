#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x; 
        A.push_back(x);
    }

    //int n= A.size();
    int count=0;
    
    vector<int>::iterator it= A.begin();
    while(it!=A.end())
    {
        if(*it!=0) {it++; continue;}
        
        count++;
        
        // vector<int>::iterator it2;
        // it2= it;
        // it2++;
        A.erase(it);
        // it = it2;
    }
    for(int i=1;i<=count;i++)
    {
        A.push_back(0);
    }
    
    for(int i=0;i<n;i++) {cout<<A[i]<<" ";}
    

}