//
// Created by Liu on 2023/7/12.
// Description:
//

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
    }
    TreeNode(int v) : val(v), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r)
    {
    }
};

vector<vector<int>> levelOrderBottom(TreeNode *root)
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
        vector<int> tempV;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *tempNode = que.front();
            que.pop();
            tempV.push_back(tempNode->val);
            if (tempNode->left != nullptr)
            {
                que.push(tempNode->left);
            }
            if (tempNode->right != nullptr)
            {
                que.push(tempNode->right);
            }
        }
        res.push_back(tempV);
    }
    reverse(res.begin(), res.end());

    return res;
}

int main()
{
}
