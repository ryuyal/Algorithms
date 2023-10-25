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

void inorder(TreeNode *root, vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
vector<int> inorderTraversal(TreeNode *root)
{

    vector<int> res;

    inorder(root, res);

    return res;
}

/*
迭代方法
*/
vector<int> inorderTraversal2(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> stk;
    TreeNode *cur = root;

    while (cur != nullptr || !stk.empty())
    {
        if (cur != nullptr)
        { // cur指针 访问节点
            stk.push(cur);
            cur = cur->left; // 一直到最左端
        }
        else
        {
            TreeNode *temp = stk.top(); // 栈顶弹出
            stk.pop();
            res.push_back(temp->val);
            cur = temp->right;
        }
    }
}

int main()
{
}
