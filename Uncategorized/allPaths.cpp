#include <vector>
#include <iostream>
using namespace std;

void dfs(int u, int target, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result)
{
    path.push_back(u);
    if (u == target)
    {
        result.push_back(path);
    }
    else
    {
        for (int v : graph[u])
        {
            dfs(v, target, graph, path, result);
        }
    }
    path.pop_back();
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    int target = n - 1;
    vector<vector<int>> graph;
    graph.resize(n);
    vector<bool> visited;
    visited.resize(n);
    for (int i = 0; i < m; i ++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    vector<vector<int>> re;
    vector<int> path;
    dfs(0, n - 1, graph, path, re);
    for (size_t i = 0; i < re.size(); i++)
    {
        for (size_t j = 0; j < re[i].size(); j++)
        {
            cout << re[i][j];
            if (j < re[i].size() - 1)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

