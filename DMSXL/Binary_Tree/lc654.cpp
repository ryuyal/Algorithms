
//
// Created by Yao on 2023/9/21.
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

TreeNode * construct(vector<int> & nums, int left, int right){
    if(left > right){
        return nullptr;
    }

    int maxValueIndex = left;
    for(int i = left; i <= right; ++i){
        if(nums[i] > nums[maxValueIndex]){
            maxValueIndex = i;
        }
    }

    TreeNode * root = new TreeNode(nums[maxValueIndex]);

    root->left = construct(nums, left, maxValueIndex-1);
    root->right = construct(nums, maxValueIndex+1, right);

    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return construct(nums, 0, nums.size()-1); // 左闭右闭区间
}

int main() {

}
