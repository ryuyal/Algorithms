
//
// Created by Yao on 2023/10/7.
// Description:     
//

#include <iostream>
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

TreeNode * build(vector<int> & nums, int left, int right) {
    if(left >= right){
        return nullptr;
    }

    int mid = left + (right-left)/2;
    TreeNode * root = new TreeNode(nums[mid]);

    root->left = build(nums, left, mid);
    root->right = build(nums, mid+1, right);

    return root;
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
    // 左闭右开区间
    TreeNode * root = build(nums, 0, nums.size());
    return root;
}

int main() {

}
