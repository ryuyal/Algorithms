//
// Created by Liu on 2023/7/19.
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


int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode *> que;

    int res = 0;
    que.push(root);
    while(!que.empty()){
        int size = que.size();

        for(int i = 0; i < size; ++i){
            TreeNode * tempNode = que.front();
            que.pop();

            if(i == 0){
                res = tempNode->val;
            }
            if(tempNode->left != nullptr){
                que.push(tempNode->left);
            }

            if(tempNode->right != nullptr){
                que.push(tempNode->right);
            }
        }
    }
    return res;
}

int main(){

}
