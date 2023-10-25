//
// Created by Liu on 2023/7/11.
// Description:
//

#include <iostream>
#include <queue>
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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode *> que;
    if (root == nullptr)
    {
        return res;
    }
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> temp;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *tempNode = que.front();
            que.pop();
            temp.push_back(tempNode->val);
            if (tempNode->left != nullptr)
            {
                que.push(tempNode->left);
            }
            if (tempNode->right != nullptr)
            {
                que.push(tempNode->right);
            }
        }

        res.push_back(temp);
    }
    return res;
}

int main()
{
}
