#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;

    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
        {
            a[i]=0;
        }

        vector<int> v; //contains indices for filling
        for(int k=n;k>=1;k--)
        {
            int last = (n/k)*k;
            int first = k;

            if(first==last)
            {
                a[last] = k;
            }
            else
            {
                int sum=0;
                for(int i=last;i>=first;i-=k)
                {
                    if(a[i]!=0)
                    {
                        sum += a[i];
                    }
                    else{
                        v.push_back(i);
                    }
                }

                int rem = sum%k;

                for(int i=0;i<v.size()-1;i++)
                {
                    a[v[i]] = k;
                }
                a[v[v.size()-1]] = k-rem;

            }


            v.clear();
        }

        for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}