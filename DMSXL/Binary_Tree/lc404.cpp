//
// Created by Liu on 2023/7/19.
// Description:
//

#include <iostream>
#include <stack>
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

// 迭代法
int sumOfLeftLeaves(TreeNode *root)
{

    if (root == nullptr)
    {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        return 0;
    }

    stack<TreeNode *> stk;
    stk.push(root);

    int sum = 0;

    while (!stk.empty())
    {
        TreeNode *tempNode = stk.top();
        stk.pop();

        if (tempNode->left != nullptr)
        { // 首先确定该节点是左节点
            if (tempNode->left->left == nullptr && tempNode->left->right == nullptr)
            { // 再确定是叶子节点
                sum += tempNode->left->val;
            }
            stk.push(tempNode->left);
        }

        if (tempNode->right != nullptr)
        {
            stk.push(tempNode->right);
        }
    }
    return sum;
}

// 递归法
int sumOfLeftLeaves2(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 0;
    }

    int leftValue = 0;
    if (root->left != nullptr)
    {
        if (root->left->left == nullptr && root->left->right == nullptr)
        {
            leftValue = root->left->val;
        }
    }
    return leftValue + sumOfLeftLeaves2(root->left) + sumOfLeftLeaves2(root->right);
}

int main()
{
}