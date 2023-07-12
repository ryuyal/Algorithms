//
// Created by Liu on 2023/7/12.
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

int minDepth(TreeNode* root) {
    if(root == nullptr){
        return 0;
    }

    if(root->left == nullptr){
        return minDepth(root->right)+1;
    }

    if(root->right == nullptr){
        return minDepth(root->left)+1;
    }

    return 1+ min(minDepth(root->left), minDepth(root->right));
}

int main(){

}