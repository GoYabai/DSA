#include <vector>
using namespace std;

//Top-down
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }

    int solve(int n, vector<int>& memo)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        if (memo[n] != -1) {
            return memo[n];
        }

        memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
        return memo[n];
    }
};

//Bottom-up
class Solution {
public:
    int climbStairs(int n) {
        int a = -1;
        int b = -1;
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        a = 1;
        b = 2;
        int curr = 0;
        for (int i = 3; i < n + 1; i++)
        {
            curr = a + b;
            a = b;
            b = curr;
        }
        return curr;
    }
};
