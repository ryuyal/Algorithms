
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

/*
 *  5 4 6 null null 3 7 这种情况出现错误
 */
//bool isValidBST(TreeNode* root) {
//    if(root == nullptr){
//        return true;
//    }
//
//    if(root->left != nullptr){
//        if(root->val <= root->left->val){
//            return false;
//        }
//    }
//
//    if(root->right != nullptr){
//        if(root->val >= root->right->val){
//            return false;
//        }
//    }
//
//    return isValidBST(root->left) && isValidBST(root->right);
//}

long long maxVal = LONG_MIN;
bool isValidBST(TreeNode * root){
    if(root == nullptr){
        return true;
    }

    bool left = isValidBST(root->left);

    //// 中序遍历，验证遍历的元素是不是从小到大
    if(maxVal < root->val){
        maxVal = root->val;
    }else{
        return false;
    }

    bool right = isValidBST(root->right);
    return left && right;

}

int main() {

}
