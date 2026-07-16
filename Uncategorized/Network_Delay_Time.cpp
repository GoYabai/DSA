#include <vector>
#include <queue>
#include <limits>

using namespace std;


const int INF = std::numeric_limits<int>::max();

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n + 1, INF);
        dis[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (!pq.empty())
        {
            int du = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (du > dis[u])
            {
                continue;
            }
            for (int i = 0; i < times.size(); i++)
            {
                if (times[i][0] == u)
                {
                    int v = times[i][1];
                    int weight = times[i][2];
                    if (dis[u] != INF && dis[u] + weight < dis[v])
                    {
                        dis[v] = dis[u] + weight;
                        pq.push({dis[v], v});
                    }
                }
            }
        }
        int max = -INF;
            for (int i = 1; i < dis.size(); i++)
            {
                if (dis[i] == INF)
                {
                    return -1;
                }
                if (dis[i] > max)
                {
                    max = dis[i];
                }
            }
            return max;
    }
};
