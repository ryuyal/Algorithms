//
// Created by Liu on 2023/7/19.
// Description: 
//

#include<iostream>
#include<vector>
#include<algorithm>
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
 * 前序遍历的变体
 */
// 传入根节点  存放结果集的res  记录每一条路径的path
void treePaths(TreeNode * root, vector<string> & res, vector<int> & path){
    path.push_back(root->val);


    if(root->left == nullptr && root->right == nullptr){ // 走到了叶子节点
        string sPath;
        // vector数组中的元素转换为string类型
        for(int i = 0; i < path.size()-1; ++i){
            sPath += to_string(path[i]);
            sPath += "->";
        }

        sPath += to_string(path[path.size()-1]);
        res.push_back(sPath);
    }

    if(root->left != nullptr ){
        treePaths(root->left, res, path);
        path.pop_back(); // 回溯
    }

    if(root->right != nullptr){
        treePaths(root->right, res, path);
        path.pop_back(); // 回溯
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    vector<int> path;

    if(root == nullptr){
        return res;
    }

    treePaths(root, res, path);

    return res;
}


int main(){

}
