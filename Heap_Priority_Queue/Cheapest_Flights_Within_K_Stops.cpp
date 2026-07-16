#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = std::numeric_limits<int>::max();

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : flights)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> dis(n, INF);
        dis[src] = 0;
        for (int time = 0; time < k + 1; time++)
        {
            vector<int> temp = dis;
            for (int u = 0; u < n; u++)
            {
                for (auto& edge : adj[u])
                {
                    int v = edge.first;
                    int weight = edge.second;
                    
                    if (dis[u] != INF && weight + dis[u] < temp[v])
                    {
                        temp[v] = weight + dis[u];
                    }
                }
            }
            dis = temp;
        }
        if (dis[dst] != INF)
        {
            return dis[dst];
        }
        return -1;
    }
};
