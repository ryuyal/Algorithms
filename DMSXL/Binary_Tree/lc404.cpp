//
// Created by Liu on 2023/7/19.
// Description: 
//

#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumOfLeftLeaves(TreeNode* root) {

    if(root == nullptr){
        return 0;
    }

    if(root->left == nullptr && root->right == nullptr){
        return 0;
    }

    stack<TreeNode *> stk;
    stk.push(root);

    int sum = 0;

    while(!stk.empty()){
        TreeNode * tempNode = stk.top();
        stk.pop();

        if(tempNode->left != nullptr){
            if(tempNode->left->left == nullptr && tempNode->left->right == nullptr){
                sum += tempNode->left->val;
            }
            stk.push(tempNode->left);
        }

        if(tempNode->right != nullptr){
            stk.push(tempNode->right);
        }
    }

    return sum;

}

int main(){

}