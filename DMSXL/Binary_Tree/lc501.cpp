
//
// Created by Yao on 2023/9/21.
// Description:     
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void getMap(TreeNode * root, unordered_map<int, int>  & uMap){
    if(root == nullptr){
        return;
    }

    getMap(root->left, uMap);
    uMap[root->val]++;
    getMap(root->right, uMap);

}

vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> uMap;
    getMap(root, uMap);

    int maxFreq = INT_MIN;
    for(auto p : uMap){
        if(p.second > maxFreq){
            maxFreq = p.second;
        }
    }

    vector<int> res;
    for(auto p : uMap){
        if(p.second == maxFreq){
            res.push_back(p.first);
        }
    }

    return res;
}

int main() {

}
