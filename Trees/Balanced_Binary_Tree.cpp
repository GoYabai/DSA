#include <cstdlib>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool isbalance = true;
        dfs(root, isbalance);
        return isbalance;
    }

    int dfs(TreeNode* root, bool& isbalance)
    {
        if (!root)
        {
            return 0;
        }

        int l = dfs(root->left, isbalance);
        int r = dfs(root->right, isbalance);
        if (abs(l - r) > 1)
        {
            isbalance = false;
        }
        return 1 + max(l, r);
    }
};
