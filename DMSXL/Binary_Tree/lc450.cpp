
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

// 删除二叉搜索树的节点
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == nullptr){
        return root;
    }

    if(root->val == key){
        // 当前节点度为0
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        // 度为1
        else if(root->left == nullptr){
            TreeNode * nextNode = root->right;
            delete root;
            return nextNode;
        }

        // 度为1
        else if(root->right == nullptr){
            TreeNode * nextNode = root->left;
            delete root;
            return nextNode;
        }

        // 度为2, 左右子节点都有：其左子树转移到其右子树的最左节点的左子树上，然后右子树顶替其位置，由此删除了该节点
        // nextNode 就是当前节点的右子树的最左节点
        TreeNode * cur = root->right;
        while(cur->left != nullptr){ // 找到待删除节点的右子树的最左节点
            cur = cur->left;
        }

        cur->left = root->left;
        TreeNode * temp = root;
        root = root->right;
        delete temp;
        return root;

    }
    if(root->val > key) root->left = deleteNode(root->left, key);
    if(root->val < key) root->right = deleteNode(root->right, key);

    return root;
}

int main() {

}
