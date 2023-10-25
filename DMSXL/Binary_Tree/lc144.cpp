//
// Created by Liu on 2023/7/11.
// Description:
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r)
    {
    }
};

void preorder(TreeNode *root, vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }

    res.push_back(root->val);

    preorder(root->left, res);
    preorder(root->right, res);
}
vector<int> preorderTraversal(TreeNode *root)
{

    vector<int> res;

    preorder(root, res);

    return res;
}

/*
    迭代遍历
*/
vector<int> preorderTraversal2(TreeNode *root)
{
    stack<TreeNode *> stk;
    vector<int> res;
    if (root == nullptr)
    {
        return res;
    }

    stk.push(root);

    while (!stk.empty())
    {
        TreeNode *temp = stk.top();
        stk.pop();

        res.push_back(temp->val);

        if (temp->right != nullptr)
        {
            stk.push(temp->right);
        }
        if (temp->left != nullptr)
        {
            stk.push(temp->left);
        }
    }
    return res;
}

int main()
{
}