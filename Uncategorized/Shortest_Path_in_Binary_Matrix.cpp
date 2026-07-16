#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int ans = 0;
        vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
        vector<int> dy = {0, -1, -1, -1, 0, 1, 1, 1};
        while (!q.empty())
        {
            int lv_size = q.size();
            ans++;
            for (int times = 0; times < lv_size; times++)
            {
                auto cor = q.front();
                q.pop();
                int x = cor.first;
                int y = cor.second;
                if (x == n - 1 && y == n - 1)
                {
                    return ans;
                }
                for (int i = 0; i < 8; i++)
                {
                    int x0 = x + dx[i];
                    int y0 = y + dy[i];
                    if (x0 < 0 || x0 >= n || y0 < 0 || y0 >= n)
                    {
                        continue;
                    }
                    if (grid[x0][y0] == 0)
                    {
                        q.push({x0, y0});
                        grid[x0][y0] = 1;
                    }
                }
            }
        }
        return -1;
    }
};