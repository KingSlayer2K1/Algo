#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[node]=true;
    for(int neigh: adj[node])
    {
        if(!visited[neigh])
        {
            dfs(neigh,adj,visited);
        }
    }
}

int count(int v, vector<vector<int>>&adj)
{
    vector<bool> visited(v,false);
    int prov=0;

    for(int i=0;i<v;++i)
    {
        if(!visited[i])
        {
            prov++;
            dfs(i,adj,visited);
        }
    }
    return prov;
}

int main()
{
    int v,e;
    cout<<"Enter the number of vertices and edges : ";
    cin>>v>>e;

    vector<vector<int>> adj(v);

    cout<<"Enter edges : \n";
    for(int i=0;i<e;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"no. of province: "<<count(v,adj)<<endl;
    return 0;
}
