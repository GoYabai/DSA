#include <vector>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }


    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = '0';
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, -1, 0, 1};
        for (int t = 0; t < 4; t++)
        {
            int x = i + dx[t];
            int y = j + dy[t];
            if (x < 0 || x >= m || y < 0 || y >= n)
            {
                continue;
            }
            if (grid[x][y] == '1')
            {
                dfs(grid, x, y);
            }
        }
    }
};
