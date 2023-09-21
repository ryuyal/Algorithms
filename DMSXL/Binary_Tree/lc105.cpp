
//
// Created by Yao on 2023/9/21.
// Description:     
//

#include <iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode * build(vector<int> pre, int l1, int r1, vector<int> in, int l2, int r2){
    if(l1 > r1 || l2 > r2){
        return nullptr;
    }

    TreeNode * root = new TreeNode(pre[l1]); // 根节点 preorder的第一个元素
    int pos = 0;
    for(int i = l2; i <= r2; ++i) {
        if (in[i] == pre[l1]) { // 找到inorder序列左右子树分界点
            pos = i;
            break;
        }
    }
    int size = pos - l2;

    // pre: 左子树[l1+1, l1+size]  右子树[l1+size+1, r1]
    // in: 左子树[l2, l2+size-1]  右子树[l2+size+1, r2]
    root->left = build(pre, l1+1, l1+size, in, l2, l2+size-1);
    root->right = build(pre, l1+size+1, r1, in, l2+size+1, r2);

    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int size = preorder.size()-1;
    return build(preorder, 0, size, inorder, 0, size);
}

int main() {

}
