#include <iostream>
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
//recursive style
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }

        if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
//for loop style
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (root == nullptr)
        {
            root = node;
        }
        else
        {
            TreeNode* curr = root;
            TreeNode* parent = nullptr;
            while (curr != nullptr)
            {
                parent = curr;
                if (val < curr->val)
                {
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
            if (val < parent->val)
            {
                parent->left = node;
            }
            else
            {
                parent->right = node;
            }
        }
        return root;
    }
};