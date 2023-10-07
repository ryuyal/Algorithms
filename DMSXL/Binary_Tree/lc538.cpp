
//
// Created by Yao on 2023/10/7.
// Description:     
//

#include <iostream>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 二叉搜索树有序
TreeNode* convertBST(TreeNode* root) {
    int pre = 0;

    stack<TreeNode*> stk;
    TreeNode * cur = root;

    while(!stk.empty() || cur != nullptr){
        if(cur != nullptr){
            stk.push(cur);
            cur = cur->right;
        }else{
            cur = stk.top();
            stk.pop();
            cur->val += pre;
            pre = cur->val;
            cur = cur->left;
        }
    }

    return root;
}

int main() {

}
