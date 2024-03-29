
//
// Created by Yao on 2023/9/22.
// Description:
//

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

TreeNode *trimBST(TreeNode *root, int low, int high)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->val < low)
    { // 到右子树
        TreeNode *right = trimBST(root->right, low, high);
        return right;
    }

    if (root->val > high)
    { // d到左子树
        TreeNode *left = trimBST(root->left, low, high);
        return left;
    }

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}

int main()
{
}
