#include <vector>
using namespace std;

//DFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];
        if (org == color) {
            return image; 
        }
        dfs(image, sr, sc, color, org);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int org)
    {
        int m = image.size();
        int n = image[0].size();
        if (sr < 0 || sr >= m || sc < 0 || sc >= n)
        {
            return;
        }
        if (image[sr][sc] != org)
        {
            return;
        }
        if (image[sr][sc] == org)
        {
            image[sr][sc] = color;
        }
        dfs(image, sr - 1, sc, color, org);
        dfs(image, sr + 1, sc, color, org);
        dfs(image, sr, sc - 1, color, org);
        dfs(image, sr, sc + 1, color, org);
        
    }
};

//BFS
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];
        if (org == color) {
            return image;
        }
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i]; 
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == org) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};