
//
// Created by Yao on 2023/9/20.
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

// preorder dfs
void traversal(TreeNode * root, vector<vector<int>> & res, vector<int> & path, int targetSum){
    if(root == nullptr){
        return ;
    }

    path.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr && targetSum-root->val == 0){ // 说明当前root节点为叶子节点 且节点值符合要求
        res.push_back(path);
        return ;
    }

    if(root->left != nullptr){
        traversal(root->left, res, path, targetSum-root->val);
        path.pop_back();
    }

    if(root->right != nullptr){
        traversal(root->right, res, path, targetSum-root->val);
        path.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> path;

    if(root == nullptr){
        return res;
    }

    traversal(root, res, path, targetSum);

    return res;
}

int main() {

}
