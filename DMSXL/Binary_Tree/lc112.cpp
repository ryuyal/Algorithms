//
// Created by Liu on 2023/7/19.
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

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->left == nullptr && root->right == nullptr && targetSum == root->val)
    {
        return true;
    }

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

/*
 * 写法二
 */
bool traversal(TreeNode *root, int sum, int targetSum)
{
    if (root == nullptr)
    {
        return false;
    }

    sum += root->val;
    if (root->left == nullptr && root->right == nullptr && sum == targetSum)
    {
        return true;
    }

    return traversal(root->left, sum, targetSum) || traversal(root->right, sum, targetSum);
}
bool hasPathSum2(TreeNode *root, int targetSum)
{
    int sum = 0;
    return traversal(root, sum, targetSum);
}

int main()
{
}
