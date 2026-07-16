#include <vector>
using namespace std;

class Solution
{
public:
    bool leadsToDestination(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph(n);
        for (vector<int> edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        if (!graph[destination].empty())
        {
            return false;
        }
        vector<int> state(n, 0);
        return dfs(graph, state, source, destination);
    }

    bool dfs(const vector<vector<int>>& graph, vector<int>& state, int node, int destination)
    {
        if (state[node] == 1) return false;
        if (state[node] == 2) return true;
        if (graph[node].empty())
        {
            return node == destination;
        }
        state[node] = 1;
        for (int neighbor : graph[node])
        {
            if (!dfs(graph, state, neighbor, destination))
            {
                return false;
            }
        }
        state[node] = 2;
        return true;
    }
};