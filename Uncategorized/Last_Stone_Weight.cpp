#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int& stone : stones)
        {
            pq.push(stone);
        }
        while (pq.size() > 1)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (x == y)
            {
                continue;
            }
            if (x < y)
            {
                pq.push(y - x);
            }
            else
            {
                pq.push(x - y);
            }
        }
        if (pq.size() > 0)
        {
            return pq.top();
        }
        return 0;
    }
};
