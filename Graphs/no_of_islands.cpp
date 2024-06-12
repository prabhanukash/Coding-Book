#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isSafe(vector<vector<int>> &adjMat, vector<vector<bool>> &visited, int i, int j)
{
    int n = adjMat.size();
    int m = adjMat[0].size();

    return (i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == false && adjMat[i][j] == 1);
}
void print(vector<vector<bool>> &visited)
{
    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited[0].size(); j++)
        {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "----------\n";
}
void DFSUtil(vector<vector<int>> &adjMat, vector<vector<bool>> &visited, int x, int y)
{
    visited[x][y] = true;
    print(visited);
    for (int i = 0; i < 4; i++)
    {
        int x_ = dx[i] + x;
        int y_ = dy[i] + y;
        if (isSafe(adjMat, visited, x_, y_))
        {
            DFSUtil(adjMat, visited, x_, y_);
        }
    }
}

int countNoOfIslands(vector<vector<int>> &adjMat)
{
    int noOfIslands = 0;
    int n = adjMat.size();
    int m = adjMat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == false && adjMat[i][j] == 1)
            {
                DFSUtil(adjMat, visited, i, j);
                noOfIslands++;
            }
        }
    }
    return noOfIslands;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjMat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adjMat[i][j];
        }
    }

    cout << countNoOfIslands(adjMat) << '\n';
    return 0;
}
