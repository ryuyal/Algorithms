//
// Created by Liu on 2023/7/14.
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
bool isSameTree(TreeNode * p, TreeNode *q){
    if(p == nullptr && q == nullptr){
        return true;
    }

    if(p != nullptr && q == nullptr){
        return false;
    }

    if(p == nullptr && q != nullptr){
        return false;
    }

    if(p->val != q->val){
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    stack<TreeNode *> stk;
    if(subRoot == nullptr){
        return true;
    }

    if(root == nullptr && subRoot != nullptr){
        return false;
    }

    stk.push(root);
    while(!stk.empty()){
        TreeNode * tempNode = stk.top();
        stk.pop();

        if(isSameTree(tempNode, subRoot)){
            return true;
        }

        if(tempNode->right != nullptr){
            stk.push(tempNode->left);
        }
        if(tempNode->left != nullptr){
            stk.push(tempNode->right);
        }
    }
    return false;
}

bool isSubtree2(TreeNode* root, TreeNode* subRoot) {
    if(root == nullptr){
        return false;
    }

    return isSameTree(root, subRoot) || isSubtree2(root->left, subRoot) || isSubtree2(root->right, subRoot);

}


int main(){

}