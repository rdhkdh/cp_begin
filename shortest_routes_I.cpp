// SSSP: Bellman Ford
//note: djikstra's is faster

#include<bits/stdc++.h>
using namespace std;

struct edge{
    int src, dest, weight;
};

struct graph{
    int v, e;
    struct edge* arr; //array of edges
};

struct graph* create_graph(int v, int e)
{
    struct graph* g = new graph;
    g->v = v;
    g->e = e;
    g->arr = new edge[e]; //array of e edges
    return g;
}

void bellman_ford(struct graph* g, int src)
{
    int v= g->v;
    int e= g->e;    
    long long dist[v];

    for(int i=0;i<v;i++)
    {
        dist[i]= LLONG_MAX;
    }
    dist[src]=0;

    for(int i=0; i<v-1; i++) //relax each of the e edges, v times
    {
        for(int j=0;j<e;j++)
        {
            int u= g->arr[j].src;
            int v= g->arr[j].dest;
            int weight= g->arr[j].weight;

            if(dist[u]!=LLONG_MAX && dist[u]+weight<dist[v])
            { //relax an edge
                dist[v]= dist[u]+weight;
            }
        }
    }

    //check for -ve weight cycles, redundant here as all weights are +ve
    // for(int i=0;i<e;i++)
    // {
    //     int u= g->arr[i].src;
    //     int v= g->arr[i].dest;
    //     int weight= g->arr[i].weight;

    //     if(dist[u]!=LLONG_MAX && dist[u]+weight<dist[v])
    //     {
    //         cout<<"Negative cycle detected.\n";
    //         return;
    //     }
    // }

    for(int i=0;i<v;i++)
    {
        cout<<dist[i]<<" ";
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    struct graph* g = create_graph(n,m);

    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        g->arr[i].src= a-1;
        g->arr[i].dest= b-1;
        g->arr[i].weight= c;
    }

    bellman_ford(g,0); //everything is 0-indexed

    return 0;
}