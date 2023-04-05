#include<bits/stdc++.h>
using namespace std;
#define int long long

int check(int x)
{
    string s = to_string(x);
    bool isFound = s.find("4") != string::npos;
    if(isFound) {return 1;}
    return 0;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;

        int count=0,num=1;

        while(count<k)
        {
            if(!check(num))
            {
                count++;
            }
            num++;
        }

        cout<<num-1<<endl;
        
    }

    return 0;
}