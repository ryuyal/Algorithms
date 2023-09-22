
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

// 同lc236 普通二叉树的做法 （没有用到二叉搜索树的特性）
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == q || root == p){
        return root;
    }

    TreeNode * left = lowestCommonAncestor(root->left, p, q);
    TreeNode * right = lowestCommonAncestor(root->right, p, q);

    if(left == nullptr){
        return right;
    }
    if(right == nullptr){
        return left;
    }

    return root;
}

// 利用二叉搜索树特性
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == q || root == p){
        return root;
    }

    if(root->val > p->val && root->val > q->val){
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        return left;
    }

    if(root->val < p->val && root->val < q->val){
        TreeNode * right = lowestCommonAncestor(root->right, p, q);
        return right;
    }

    return root;
}
int main() {

}
