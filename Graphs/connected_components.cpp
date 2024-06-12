#include <bits/stdc++.h>
using namespace std;
class Graph
{
  int V;
  vector<vector<int>> adj;
  int noOfconnectedComponents;
  void DFSUtil(int v, vector<bool> &visited)
  {
    cout << v << " ";
    visited[v] = true;
    for (int u : adj[v])
    {
      if (!visited[u])
      {
        DFSUtil(u, visited);
      }
    }
  }

public:
  Graph(int V) : V(V), noOfconnectedComponents(0), adj(V) {}

  void addEdge(int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void connectedComponents()
  {
    vector<bool> visited(V, false);
    for (int v = 0; v < V; v++)
    {
      if (visited[v] == false)
      {
        noOfconnectedComponents++;
        DFSUtil(v, visited);
        cout << "\n";
      }
    }
    cout << "number of connected components in the graph is: ";
    cout << noOfconnectedComponents << endl;
  }
};
int main()
{
  Graph g(8);
  g.addEdge(0, 1);
  // g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 6);  
  g.addEdge(6, 5);      
  g.addEdge(5, 3);
  g.addEdge(4, 7);      

  g.connectedComponents();

  return 0;
}