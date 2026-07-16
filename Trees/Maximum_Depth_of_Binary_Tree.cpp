#include <iostream>
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

//BFS
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        int h = 0;
        while (!q.empty())
        {
            int lv_size = q.size();
            for (int i = 0; i < lv_size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            h++;
        }
        return h;
    }
};

//DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};