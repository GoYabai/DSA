#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, -1);
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == -1) {
                if (!dfs(adj, visited, i)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(std::vector<std::vector<int>>& adj, std::vector<int>& visited, int u) {
        visited[u] = 0; 
        for (auto& v : adj[u]) {
            if (visited[v] == 0) {
                return false;
            }
            if (visited[v] == -1) {
                if (!dfs(adj, visited, v)) {
                    return false; 
                }
            }
        }
        visited[u] = 1; 
        return true;
    }
};
