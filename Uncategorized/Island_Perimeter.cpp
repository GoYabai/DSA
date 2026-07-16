#include <vector>
#include <queue>
using namespace std;

//DFS
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return dfs(grid, i, j);
                }
            }
        }
    }

    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return 1;
        }
        if (grid[i][j] == 0)
        {
            return 1;
        }
        if (grid[i][j] == -1)
        {
            return 0;
        }
        grid[i][j] = -1;
        return dfs(grid, i - 1, j) +
               dfs(grid, i + 1, j) +
               dfs(grid, i, j - 1) +
               dfs(grid, i, j + 1);
    }
};


//BFS
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    grid[i][j] = -1;
                    while (!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();
                        for (int t = 0; t < 4; t++)
                        {
                            int x = r + dx[t];
                            int y = c + dy[t];
                            if (x < 0 || x >= m || y < 0 || y >= n)
                            {
                                ans += 1;
                            }
                            else if (grid[x][y] == 0)
                            {
                                ans += 1;
                            }
                            else if (grid[x][y] == 1)
                            {
                                q.push({x, y});
                                grid[x][y] = - 1;
                            }
                        }
                    }
                    return ans;
                }
            }
        }
        return ans;
    }

};