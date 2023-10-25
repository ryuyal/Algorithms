
//
// Created by Yao on 2023/9/21.
// Description:
//

#include <iostream>
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
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right)
    {
    }
};

// 中序 + 后序 构造 二叉树
TreeNode *build(vector<int> &inorder, int l1, int r1, vector<int> &postorder, int l2, int r2)
{
    if (l1 > r1 || l2 > r2)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(postorder[r2]);
    int x = 0;
    for (int i = l1; i <= r1; ++i)
    {
        if (inorder[i] == postorder[r2])
        { // 找到中序序列中左右子树分界点
            x = i;
            break;
        }
    }
    // 此时inorder： 左子树 [l1, x-1], 右子树[x+1, r1]
    // postorder： 左子树[l2, l2+size-1], 右子树[l2+size, r2-1]
    int size = x - l1;                                                    // 左子树的节点数
    root->left = build(inorder, l1, x - 1, postorder, l2, l2 + size - 1); // 左
    root->right = build(inorder, x + 1, r1, postorder, l2 + size, r2 - 1);

    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{

    TreeNode *root = build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

    return root;
}

int main()
{
}
