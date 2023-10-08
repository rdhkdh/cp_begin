#include<bits/stdc++.h>
using namespace std;

const int MAX= 1e5+10;
int s,e;
int visited[MAX]={0}, parent[MAX];
vector<int> adj[MAX];

bool dfs(int x= 1, int p=0)
{
    visited[x]= 1;
    parent[x]= p;
    for(int u: adj[x])
    {
        if(u==p) { continue; }
        
        if(visited[u]) // and not parent
        {
            s = u;
            e = x;
            return true; //found a cycle
        }
        else
        { 
            if(dfs(u,x)) {return true;} //do dfs with x as parent of u
        }
    }
    return false; //not found any cycle
}

bool visit_all(int n)
{
	for(int i = 1; i <= n; ++i)
	{
		if(!visited[i]) { if(dfs(i,-1)) return true; }
	}
	return false;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(!visit_all(n))
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

    int temp=e; //end
    vector<int> ans;
    ans.push_back(e); //end
    while(temp!=s)
    {
        ans.push_back(parent[temp]);
        temp= parent[temp];
    }
    ans.push_back(e);
    cout<<ans.size()<<endl;
    for(auto c: ans) {cout<<c<<" ";}
    

}