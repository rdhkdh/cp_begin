#include<bots/stdc++.h>
#define maxn 1005
using namespace std;
char mat[maxn][maxn];
int visited[maxn][maxn]; 
vector<char> result;

void dfs(int i, int j)
{
    int flag=0,count=0; //assuming no path
    if(mat[i][j]=='B') {flag=1; return;}
    else{
        visited[i][j]=1;
        if() {dfs(i+1,j);}

    }
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    int A_i,A_j;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            visited[i][j]=0;
            if(mat[i][j]=='A') {A_i=i; A_j=j;}
        }
    }
    result.clear();
    dfs(A_i,A_j);

    return 0;
}