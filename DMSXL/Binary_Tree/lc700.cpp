
//
// Created by Yao on 2023/9/21.
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

TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr){
        return nullptr;
    }

    if(root->val == val){
        return root;
    }

    if(root->val > val){
        return searchBST(root->left, val);
    }else{
        return searchBST(root->right, val);
    }
}

int main() {

}
