#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,n;
    cin>>x>>n;
    int p[n];
    for(int i=0;i<n;i++) {cin>>p[i];}

    set<int> traf_lights;
    set<int> diff;
    map<int,int> freq; //frequencies of the differences

    traf_lights.insert(0); traf_lights.insert(x);
    diff.insert(x); freq[x]++;
    for(int i=0;i<n;i++)
    {
        set<int>::iterator it_next,it_prev;
        auto it = traf_lights.insert(p[i]);
        it_next = it.first;
        it_next++;
        it_prev = it.first;
        it_prev--;

        int temp = *it_next - *it_prev;
        int r1 = *it_next - p[i];
        int r2 = p[i] - *it_prev;

        freq[temp]--;
        if(freq[temp]==0) {diff.erase(temp);}
        
        diff.insert(r1); freq[r1]++;
        diff.insert(r2); freq[r2]++;

        cout<<*diff.rbegin()<<" ";
    }
}