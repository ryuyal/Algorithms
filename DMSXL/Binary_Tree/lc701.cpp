
//
// Created by Yao on 2023/9/22.
// Description:     
//

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// My
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == nullptr){
        return new TreeNode(val);
    }

    // 到达叶子节点
    if(root->left == nullptr && root->right == nullptr){
        if(root->val < val){
            root->right = new TreeNode(val);
        }
        if(root->val > val){
            root->left = new TreeNode(val);
        }
    }

    // 左子树为空且根节点值大于val--左节点
    if(root->left == nullptr && root->val > val){
        root->left = new TreeNode(val);
    }

    // 右子树为空且根节点值小于val--右节点
    if(root->right == nullptr && root->val < val){
        root->right = new TreeNode(val);
    }


    if(root->val < val){
        insertIntoBST(root->right, val);
    }
    if(root->val > val){
        insertIntoBST(root->left, val);
    }

    return root;
}

// 精简版
TreeNode* insertIntoBST2(TreeNode* root, int val) {
    if(root == nullptr){
        return new TreeNode(val);
    }

    if(root->val < val){
        root->right = insertIntoBST(root->right, val);
    }
    if(root->val > val){
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}



int main() {

}
