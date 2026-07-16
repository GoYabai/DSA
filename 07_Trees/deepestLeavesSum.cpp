#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    vector<int> L(n), R(n);
    int root = 0;
    queue<int> q;
    q.push(root);
    int deepestLeavesSum = 0;

    while (!q.empty())
    {
        int levelSize = q.size();
        deepestLeavesSum = 0;

        for (int i = 0; i < levelSize; ++i)
        {
            int u = q.front();
            q.pop();

            deepestLeavesSum += values[u];
            if (L[u] != -1) q.push(L[u]);
            if (R[u] != -1) q.push(R[u]);
        }
    }
    cout << deepestLeavesSum << "\n";
    return 0;
}