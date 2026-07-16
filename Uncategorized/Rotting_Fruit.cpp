#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }
        int ans = 0;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        while (!q.empty() && fresh_count > 0) {
            int lv_size = q.size();
            for (int a = 0; a < lv_size; a++) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int x0 = x + dx[k];
                    int y0 = y + dy[k];
                    if (x0 >= 0 && x0 < m && y0 >= 0 && y0 < n && grid[x0][y0] == 1) {
                        grid[x0][y0] = 2;
                        q.push({x0, y0});
                        fresh_count--;
                    }
                }
            }
            ans++;
        }
        if (fresh_count > 0) {
            return -1;
        }
        return ans;
    }
};