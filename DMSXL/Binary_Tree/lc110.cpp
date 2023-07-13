//
// Created by Liu on 2023/7/14.
// Description: 
//

#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getDepth(TreeNode * root){
    if(root == nullptr){
        return 0;
    }

    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }

    return max(getDepth(root->left), getDepth(root->right))+1;
}

// 平衡二叉树 左右子树之差不超过1
bool isBalanced(TreeNode* root) {
    if(root == nullptr){
        return true;
    }

    if(root->left == nullptr && root->right == nullptr){
        return true;
    }

    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    if(abs(leftDepth - rightDepth) > 1){
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

int main(){

}