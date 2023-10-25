//
// Created by Liu on 2023/7/12.
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

vector<int> largestValues(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
    {
        return res;
    }

    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        int size = que.size();
        int maxTemp = que.front()->val;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *tempNode = que.front();
            que.pop();

            maxTemp = max(maxTemp, tempNode->val);

            if (tempNode->left != nullptr)
            {
                que.push(tempNode->left);
            }

            if (tempNode->right != nullptr)
            {
                que.push(tempNode->right);
            }
        }

        res.push_back(maxTemp);
    }
    return res;
}

int main()
{
}
