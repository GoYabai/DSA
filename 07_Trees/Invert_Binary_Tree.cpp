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

//DFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            return nullptr;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

//BFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
        {
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            swap(curr->left, curr->right);
            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }
        }
        return root;
    }
};