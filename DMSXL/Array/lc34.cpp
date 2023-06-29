//
// Created by Liu on 2023/6/29.
//

#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int> & nums, int target){
    if (nums.empty()){
        return {-1, -1};
    }

    int left = -1, right = nums.size();

    vector<int> res(2);
    // 找到最后一个小于target的元素
    while(left + 1 != right){
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target){
            right = mid;
        }else{
            left = mid;
        }
    }
    if (right != nums.size() && nums[right] == target){
        res[0] = right;
    }else{
        res[0] = -1;
    }

    // 找到第一个大于target的元素
    left = -1, right = nums.size();
    while(left + 1 != right){
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target){
            left = mid;
        }else{
            right = mid;
        }
    }
    if (left != -1 && nums[left] == target){
        res[1] = left;
    }else{
        res[1] = -1;
    }

    return res;
}


int main(){

    int n;
    cout << "Please input the size of vector: " << endl;
    cin >> n;

    cout << "Please input elements of vector: " << endl;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    cout << "Please input the target num: " << endl;
    int target;
    cin >> target;

    vector<int> res = searchRange(nums, target);
    for (int num : res) {
        cout << num << " ";
    }

}