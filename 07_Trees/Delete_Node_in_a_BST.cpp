#include <iostream>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        while (curr != nullptr)
        {
            if (curr->val == key)
            {
                break;
            }
            else if (curr-> val > key)
            {
                parent = curr;
                curr = curr->left;
            }
            else
            {
                parent = curr;
                curr = curr->right;
            }
        }
        if (curr == nullptr)
        {
            return root;
        }
        if (curr->left != nullptr && curr->right != nullptr)
        {
            TreeNode* child = curr->right;
            TreeNode* father = curr;
            while (child->left != nullptr)
            {
                father = child;
                child = child->left;
            }
            curr->val = child->val;
            curr = child;
            parent = father;
        }
        TreeNode* temp;
        if (curr->left == nullptr)
        {
            temp = curr->right;
        }
        else
        {
            temp = curr->left;
        }
        if (parent == nullptr)
        {
            delete curr;
            return temp;
        }
        if (parent->left == curr)
        {
            parent->left = temp;
        }
        else
        {
            parent->right = temp;
        }
        delete curr;
        return root;
    }
};