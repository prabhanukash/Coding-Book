#include <bits/stdc++.h>
using namespace std;

class Graph
{
      int V;
      map<char, set<char>> adj; // for storing in ascending order which will be lexicographic order
    
      void DFSUtil(char v, map<char, bool> &visited)
      {
            visited[v] = true;
            cout << v << " "; 
            for (int u : adj[v])
            {
                  if (!visited[u])
                  {
                        DFSUtil(u, visited);
                  }
            }
      }

public:
      Graph(int V) : V(V) {}

      void addEdge(int u, int v)
      {
            adj[u].insert(v);
            adj[v].insert(u);
      }

      void DFS(int start)
      {
        map<char, bool> visited;
        DFSUtil(start, visited);
      }
};
int main()
{
      Graph g(10);
      g.addEdge('a', 'y');
      g.addEdge('a', 'z');
      g.addEdge('a', 'p');
      g.addEdge('p', 'c');
      g.addEdge('p', 'b');  
      g.addEdge('y', 'm');      
      g.addEdge('y', 'l');
      g.addEdge('z', 'h');      
      g.addEdge('z', 'g');      
      g.addEdge('z', 'i');      


      g.DFS('a');
}