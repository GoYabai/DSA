#include <vector>
#include <queue>
using namespace std;

//DFS
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(adj, source, destination, visited);
    }

    bool dfs(vector<vector<int>>& adj, int s, int d, vector<bool>& visited)
    {
        if (s == d)
        {
            return true;
        }
        visited[s] = true;
        int lv_size = adj[s].size();
        for (int i = 0; i < lv_size; i++)
        {
            int t = adj[s][i];
            if (visited[t] != true)
            {
                if (dfs(adj, t, d, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//BFS
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            if (t == destination)
            {
                return true;
            }
            for (auto& edge : adj[t])
            {
                if (!visited[edge])
                {
                    q.push(edge);
                    visited[edge] = true;
                }
            }
        }
        return false;
    }
};