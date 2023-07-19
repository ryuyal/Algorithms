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


void treePaths(TreeNode * root, vector<string> & res, vector<int> & path){
    path.push_back(root->val);

    if(root->left == nullptr && root->right == nullptr){
        string sPath;
        for(int i = 0; i < path.size()-1; ++i){
            sPath += to_string(path[i]);
            sPath += "->";
        }

        sPath += to_string(path[path.size()-1]);
        res.push_back(sPath);
    }

    if(root->left != nullptr ){
        treePaths(root->left, res, path);
        path.pop_back();
    }

    if(root->right != nullptr){
        treePaths(root->right, res, path);
        path.pop_back();
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
