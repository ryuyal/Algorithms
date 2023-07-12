//
// Created by Liu on 2023/7/12.
// Description: 
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(){}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
    TreeNode(int v, TreeNode * l, TreeNode * r):val(v), left(l), right(r){}

};

vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode *> que;

    vector<int> res;
    if(root == nullptr){
        return res;
    }

    que.push(root);

    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; ++i){
            TreeNode * tempNode = que.front();
            que.pop();
            if(i == size-1){
                res.push_back(tempNode->val);
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
