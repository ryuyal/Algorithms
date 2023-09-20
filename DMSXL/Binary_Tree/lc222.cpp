//
// Created by Liu on 2023/7/14.
// Description: 
//

#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 普通二叉树 计算节点个数
// 时间复杂度O(n) 空间复杂度O(logn)
int countNodes(TreeNode* root) {
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }

    return 1+countNodes(root->left) + countNodes(root->right);
}

// 完全二叉树
int countNodes2(TreeNode * root){
    if(root == nullptr){
        return 0;
    }

    // 判断向左遍历的深度和向右遍历的深度是否相等, 相等说明是满二叉树
    TreeNode * leftNode = root->left;
    TreeNode * rightNode = root->right;

    int leftDepth = 0, rightDepth = 0;
    while(leftNode){
        leftNode = leftNode->left;
        leftDepth++;
    }
    while(rightNode){
        rightNode = rightNode->right;
        rightDepth++;
    }

    if(leftDepth == rightDepth){
        return (2<<leftDepth) - 1; // 树的高度为 h时, 满二叉树节点个数为 2^h-1
    }

    return countNodes2(root->left) + countNodes2(root->right) + 1;
}

int main(){

}