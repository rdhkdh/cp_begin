#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int unique=0;

    set<int> nums;
    map<int,int> freq;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        nums.insert(a[i]);
        freq[a[i]]++;
    }

    while(nums.size()!=0)
    {
        int m = *nums.rbegin();
        if(freq[m]==1)
        {
            unique++;
            nums.erase(m);
            freq.erase(m);
            if(m/2!=0) 
            {
                nums.insert(m/2); 
                freq[m/2]++;
            }
        }
        else
        {
            nums.erase(m);
            freq.erase(m);
        }
    }

    cout<<unique<<endl;
}