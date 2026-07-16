#include <queue>
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

//DFS
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return dfs(p, q);
    }

    bool dfs(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }
        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }
};

//BFS
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return bfs(p, q);
    }

    bool bfs(TreeNode* p, TreeNode* q)
    {
        queue<TreeNode*> qp;
        queue<TreeNode*> qq;
        qp.push(p);
        qq.push(q);
        while (!qp.empty() && !qq.empty())
        {
            TreeNode* a = qp.front(); qp.pop();
            TreeNode* b = qq.front(); qq.pop();
            if (a == nullptr && b == nullptr)
            {
                continue;
            }
            if (a == nullptr || b == nullptr)
            {
                return false;
            }
            if (a->val != b->val)
            {
                return false;
            }
            qp.push(a->left);
            qq.push(b->left);
            
            qp.push(a->right);
            qq.push(b->right);
        }
        return qp.empty() && qq.empty();
    }
};
