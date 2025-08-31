#include<bits/stdc++.h>
using namespace std;

vector<int> bfsT(int n, vector<vector<int>> & adj)
{
    vector<int> bfs;
    vector<bool> visited(n,false);

    for(int start=0; start<n; start++)
    {
        if(!visited[start])
        {
            queue<int> q;
            q.push(start);
            visited[start]=true;

            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                bfs.push_back(node);

                //visit all unvisited neighbours 
                for(int neigh: adj[node])
                {
                    if(!visited[neigh])
                    {
                        visited[neigh]=true;
                        q.push(neigh);
                    }
                }
            }
        }
        
    }
    return bfs;
}

int main()
{
    int n,m;
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>m;
    vector<vector<int>> adj(n);
    
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Assuming nodes are 0-based, add edge in both directions
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Perform BFS
    vector<int> result = bfsT(n, adj);

    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
