
//
// Created by Yao on 2023/9/21.
// Description:     
//

#include <iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int getMinimumDifference(TreeNode* root) {
    // 中序遍历
    int res = INT_MAX;
    stack<TreeNode *> stk;

    TreeNode * cur = root;
    TreeNode * pre = nullptr;

    while(cur != nullptr || !stk.empty()){
        if(cur != nullptr){
            stk.push(cur);
            cur = cur->left;
        }else{
            cur = stk.top();
            stk.pop();
            if(pre != nullptr){
                res = min(res, cur->val - pre->val);
            }
            pre = cur;
            cur = cur->right;
        }
    }
    return res;
}

void getVector(TreeNode * root, vector<int> & v){
    if(root == nullptr){
        return ;
    }

    getVector(root->left, v);
    v.push_back(root->val);
    getVector(root->right, v);
}

int getMinimumDifference2(TreeNode* root) {
    // 中序遍历
    vector<int> v;
    getVector(root, v);

    int res = INT_MAX;

    for(int i = 1; i < v.size(); ++i){
        res = min(res, v[i]-v[i-1]);
    }

    return res;
}

int main() {

}
