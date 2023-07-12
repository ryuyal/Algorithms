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

vector<double> averageOfLevels(TreeNode* root) {

    queue<TreeNode *> que;

    vector<double> res;
    if(root == nullptr){
        return res;
    }

    que.push(root);

    while(!que.empty()){
        int size = que.size();
        double sum = 0;
        for(int i = 0; i < size; ++i){
            TreeNode * tempNode = que.front();
            que.pop();
            sum += tempNode->val;

            if(tempNode->left != nullptr){
                que.push(tempNode->left);
            }
            if(tempNode->right != nullptr){
                que.push(tempNode->right);
            }
        }

        res.push_back(double(sum) / size);
    }
    return res;
}

int main(){

}
