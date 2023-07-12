//
// Created by Liu on 2023/7/12.
// Description: 
//

#include <iostream>

using namespace std;
struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode * l, TreeNode * r): val(x), left(l), right(r){}

};

TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return root;
    }

    TreeNode * tempNode = root->left;
    root->left = root->right;
    root->right = tempNode;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main() {

}
