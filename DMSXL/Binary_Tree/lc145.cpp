//
// Created by Liu on 2023/7/11.
// Description: 
//

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode * l, TreeNode * r): val(x), left(l), right(r){}
};

void postorder(TreeNode * root, vector<int> & res){
    if(root == nullptr){
        return ;
    }

    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {

    vector<int> res;

    postorder(root, res);

    return res;
}

vector<int> postorderTraversal2(TreeNode * root){
    vector<int> res;

    if(root == nullptr){
        return res;
    }

    stack<TreeNode *> stk;

    stk.push(root);
    while(!stk.empty()){
        TreeNode * temp = stk.top();
        stk.pop();
        res.push_back(temp->val);

        if(temp->left != nullptr){
            stk.push(temp->left);
        }

        if(temp->right != nullptr){
            stk.push(temp->right);
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

int main(){

}