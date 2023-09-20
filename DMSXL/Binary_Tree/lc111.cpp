//
// Created by Liu on 2023/7/12.
// Description: 
//

#include<iostream>
#include<queue>
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

// 层序遍历的方法
int minDepth2(TreeNode* root) {
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }

    queue<TreeNode *> que;
    que.push(root);

    int min_depth = 0;
    while(!que.empty()){
        int size = que.size();
        ++min_depth;
        for(int i = 0; i < size; ++i){
            TreeNode * temp_node = que.front();
            que.pop();
            if(temp_node->left == nullptr && temp_node->right == nullptr){
                return min_depth;
            }
            if(temp_node->left != nullptr){
                que.push(temp_node->left);
            }
            if(temp_node->right != nullptr){
                que.push(temp_node->right);
            }
        }
    }
    return min_depth;
}

int main(){

}