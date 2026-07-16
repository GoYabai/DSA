#include <vector>
using namespace std;

//Top-down
class Solution {
public:
    int solve(int n, vector<int>& f)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (f[n] != -1)
        {
            return f[n];
        }
        f[n] = solve(n - 1, f) + solve(n - 2, f);
        return f[n];
    }



    int fib(int n) {
        vector<int> f(n + 1, -1);
        return solve(n, f);        
    }
};

//Bottom-up
class Solution {
public:
    int fib(int n) {
        vector<int> f(n+1, -1);
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};