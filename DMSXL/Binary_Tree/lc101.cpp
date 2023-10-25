//
// Created by Liu on 2023/7/14.
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

bool compare(TreeNode *leftNode, TreeNode *rightNode)
{
    if (leftNode == nullptr && rightNode != nullptr)
    {
        return false;
    }
    if (leftNode != nullptr && rightNode == nullptr)
    {
        return false;
    }

    if (leftNode == nullptr && rightNode == nullptr)
    {
        return true;
    }

    if (leftNode->val != rightNode->val)
    {
        return false;
    }

    return compare(leftNode->left, rightNode->right) && compare(leftNode->right, rightNode->left);
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }

    return compare(root->left, root->right);
}

int main()
{
}
