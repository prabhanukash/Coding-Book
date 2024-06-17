#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int V;
    vector<vector<int>> adjList;
    vector<int> state; // 0: unvisited, 1: visiting, 2: visited

    bool dfs(int v, vector<int> &cycle)
    {
        state[v] = 1; // not fully processed
        cycle.push_back(v);
        for (int nb : adjList[v])
        {
            if (state[nb] == 0)
            { // not yet explored
                if (dfs(nb, cycle))
                    return true;
            }
            else if (state[nb] == 1)
            { // cycle has detected
                return true;
            }
        }
        state[v] = 2; // fully processed
        cycle.pop_back();
        return false;
    }

public:
    Graph(int v) : V(v), adjList(V), state(V, 0) {}

    void addEdge(int from, int to)
    {
        if (from >= V or to >= V)
        {
            cerr << "Error: Node index out of bound." << endl;
            return;
        }
        adjList[from].push_back(to);
    }

    vector<int> findCycle()
    {
        for (int v = 0; v < V; v++)
        {
            if (state[v] == 0)
            {
                vector<int> cycle;
                if (dfs(v, cycle))
                    return cycle;
            }
        }
        return {};
    }
    bool hasCycle()
    {
        return !findCycle().empty();
    }
    bool isTree()
    {
        // Check connectedness
        queue<int> q;
        q.push(0);    // Start from any node
        state[0] = 1; // Mark the starting node as visited

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int nb : adjList[curr])
            {
                if (state[nb] == 0)
                {                  // If neighbor is unvisited, visit it
                    state[nb] = 1; // Mark neighbor as visited
                    q.push(nb);
                }
            }
        }

        // If any node remains unvisited, graph is not connected
        for (int i = 0; i < V; ++i)
        {
            if (state[i] == 0)
            {
                return false;
            }
        }

        // Check for cycles starting from each node
        fill(state.begin(), state.end(), 0); // Reset state for cycle detection
        if (hasCycle())
        {                 // Start DFS from any node with no parent (-1)
            return false; // Cycle found, not a tree
        }

        return true; // Graph is connected and has no cycles, it's a tree
    }
};
int main()
{
    try
    {
        // Test case 1: Cycle exists
        Graph g1(3);
        g1.addEdge(0, 1);
        g1.addEdge(1, 2);
        g1.addEdge(2, 0);
        vector<int> cycle;
        cycle = g1.findCycle();
        if (!cycle.empty())
        {
            cout << "Cycle components: ";
            for (int node : cycle)
            {
                cout << node << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No cycles found." << endl;
        }
        cycle.clear();
        // Test case 2: No cycle
        Graph g2(4);
        g2.addEdge(0, 1);
        g2.addEdge(1, 2);
        g2.addEdge(2, 3);
        cycle = g2.findCycle();
        if (!cycle.empty())
        {
            cout << "Cycle components: ";
            for (int node : cycle)
            {
                cout << node << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No cycles found." << endl;
        }
        cycle.clear();

        // Test case 3: Cycle exists
        Graph g3(4);
        g3.addEdge(0, 1);
        g3.addEdge(1, 2);
        g3.addEdge(2, 3);
        g3.addEdge(3, 1);
        cycle = g3.findCycle();
        if (!cycle.empty())
        {
            cout << "Cycle components: ";
            for (int node : cycle)
            {
                cout << node << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No cycles found." << endl;
        }
        cycle.clear();
        // Test case 4: Empty graph
        Graph g4(0);
        cycle = g4.findCycle();
        if (!cycle.empty())
        {
            cout << "Cycle components: ";
            for (int node : cycle)
            {
                cout << node << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No cycles found." << endl;
        }
        cycle.clear();
        // Test case 5: Single node without edges
        Graph g5(1);
        cycle = g5.findCycle();
        if (!cycle.empty())
        {
            cout << "Cycle components: ";
            for (int node : cycle)
            {
                cout << node << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No cycles found." << endl;
        }
        cycle.clear();
        // Test case 6: Single node with a self-loop
        Graph g6(1);
        g6.addEdge(0, 0);
        cycle = g6.findCycle();
        if (!cycle.empty())
        {
            cout << "Cycle components: ";
            for (int node : cycle)
            {
                cout << node << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No cycles found." << endl;
        }
        cycle.clear();
        // Test case
        Graph g(5);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);

        cout << "Is the graph a tree? " << (g.isTree() ? "Yes" : "No") << endl;
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}