#include <bits/stdc++.h>
using namespace std;

class Graph
{
      int V;
      vector<vector<int>> adj;

      void DFSUtil(int v, vector<bool> &visited)
      {
            visited[v] = true;
            cout << v << " "; // forward traversal
            for (int u : adj[v])
            {
                  if (!visited[u])
                  {
                        DFSUtil(u, visited);
                  }
            }
            // cout << v << " "; // backward traversal
      }

public:
      Graph(int V) : V(V), adj(V) {}

      void addEdge(int u, int v)
      {
            adj[u].push_back(v);
            adj[v].push_back(u);
      }

      void DFS(int start)
      {
            vector<bool> visited(V, false);
            DFSUtil(start, visited);
      }
};
int main()
{
      Graph g(8);
      g.addEdge(0, 1);
      g.addEdge(0, 4);
      g.addEdge(1, 2);
      g.addEdge(1, 3);
      g.addEdge(2, 6);  
      g.addEdge(6, 5);      
      g.addEdge(5, 3);
      g.addEdge(4, 7);      


      g.DFS(0);
}