#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int h[n];

    int index = -1;
    for(int i=0;i<n;i++)
    {
        cin>>h[i];

        if(i>0)
        {
            if(h[i]>h[0])
            {
                index = i;
                break;
            }
        }
    }
    if(index!=-1)
    {
        cout<<index+1<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    
    
}