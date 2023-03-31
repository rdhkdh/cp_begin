#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>> v; //list of moves

void tower_of_hanoi(int source, int temp, int dest, int n)
{
    if(n==1) { v.push_back(make_pair(source,dest)); return; }

    tower_of_hanoi(source,dest,temp,n-1); //n-1 disks from source to temp
    v.push_back(make_pair(source,dest)); //nth disk from source to dest
    tower_of_hanoi(temp,source,dest,n-1); //n-1 disks from temp to dest
}

int32_t main()
{
    int n;
    cin>>n;
    v.clear();
    tower_of_hanoi(1,2,3,n);
    cout<<v.size()<<endl;

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}