//
// Created by Liu on 2023/6/29.
//

#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int> & nums, int target){
    int left = -1, right = nums.size();

    while(left + 1 != right){
        int mid = left + (right - left) /2;
        if (nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            left = mid;
        }else{
            right = mid;
        }
    }
    return right;
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

    int res = searchInsert(nums, target);
    cout << res;

}