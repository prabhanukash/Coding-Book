#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isSafe(vector<vector<int>> &adjMat, vector<vector<bool>> &visited, int x, int y)
{
  int n = adjMat.size();
  int m = adjMat[0].size();

  return (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == false && adjMat[x][y] == 1);
}
void print(vector<vector<int>> & adjMat){
  for (int i = 0; i < adjMat.size();i++){
    for (int j = 0; j < adjMat[0].size();j++){
      cout << adjMat[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << "------------\n";
}
void DFSUtil(vector<vector<int>> &adjMat, vector<vector<bool>> &visited, int x, int y)
{
  visited[x][y] = true;
  adjMat[x][y] = 0;
  print(adjMat);

  for (int i = 0; i < 4; i++)
  {
    int x_ = dx[i] + x;
    int y_ = dy[i] + y;
    if(isSafe(adjMat, visited, x_, y_)){
      DFSUtil(adjMat, visited, x_, y_);
		}
  }
}

int countNoOfEnclaves(vector<vector<int>> adjMat)
{
  int n = adjMat.size();
  int m = adjMat[0].size();
  int noOfEnclaves = 0;
	vector<vector<bool>> visited(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
      {
        if (adjMat[i][j] == 1)
        {
          DFSUtil(adjMat, visited, i, j);
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (adjMat[i][j] == 1)
      {
        noOfEnclaves++;
      }
    }
  }

  return noOfEnclaves;
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

  cout << countNoOfEnclaves(adjMat) <<'\n';
  return 0;
}
