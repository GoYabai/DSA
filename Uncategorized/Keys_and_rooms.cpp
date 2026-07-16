#include <vector>
#include <queue>
using namespace std;

//DFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int l = rooms.size();
        vector<bool> visited(l, false);
        dfs(rooms, 0, visited);
        for (int i = 0; i < l; i++)
        {
            if (!visited[i])
            {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>>& rooms, int s, vector<bool>& visited)
    {
        visited[s] = true;
        for (auto& edge : rooms[s])
        {
            if (!visited[edge])
            {
                dfs(rooms, edge, visited);
            }
        }
    }
};

//BFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int l = rooms.size();
        vector<bool> visited(l, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int lv_size = q.size();
            for (int i = 0; i < lv_size; i++)
            {
                int k = q.front();
                q.pop();
                for (auto &edge : rooms[k])
                {
                    if (!visited[edge])
                    {
                        visited[edge] = true;
                        q.push(edge);
                    }
                }
            }
        }
        for (int i = 0; i < l; i++)
        {
            if (!visited[i])
            {
                return false;
            }
        }
        return true;
    }

};