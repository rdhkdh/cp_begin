#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    if(k>0)
    {
        cout<<"Yes"<<endl;
        sort(A,A+n);
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" "; //good seq
        }
    }
    else{
        sort(A,A+n);
        reverse(A,A+n);

        //checking if all cumulative sums are >=0
        int flag=0;
        int Y[n+1];
        Y[0]=0;
        for(int i=1;i<n;i++)
        {
            Y[i] = Y[i-1]+A[i];
            if(Y[i]<0)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<A[i]<<" ";
            }
        }
    }

    return 0;
}