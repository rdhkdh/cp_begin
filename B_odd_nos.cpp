#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {int x; cin>>x; A.push_back(x);}
    int B;
    cin>>B;
    int odd_count[n];

    if(A[0]%2==1) {odd_count[0]=1;}
    else{odd_count[0]=0;}
    for(int i=1;i<n;i++)
    {
        if(A[i]%2==1)  odd_count[i] = odd_count[i-1]+1;
        else{ odd_count[i]=odd_count[i-1];}
    }

    
    int j=n-1,flag=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        j=n-1;
        while(j>i)
        {
            int diff = odd_count[j]-odd_count[i];
            if(A[i]%2==1) {diff++;}
            if(diff==B) 
            {
                count++; 
                j--;
            }
            else if(diff<B)
            {
                break;
            }
            else if(diff>B)
            {
                j--;
            }
        }
    }
    

    if(B==0) 
    {
        for(int i=0;i<n;i++)
        {
            if(A[i]%2==0) {count++;} //1 membered arrays
        }
    }
    if(B==1)
    {
        for(int i=0;i<n;i++)
        {
            if(A[i]%2==1) {count++;} //1 membered arrays
        }
    }
    
    cout<< count;

}

