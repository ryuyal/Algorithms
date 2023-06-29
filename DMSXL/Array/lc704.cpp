//
// Created by Liu on 2023/6/29.
//

#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> & nums, int target){
    int len = nums.size();

    int left = -1, right = len;
    while(left + 1 != right){
        int mid = left + (right - left)/2;
        if (nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            left = mid;
        }else{
            right = mid;
        }
    }

    return -1;
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

    int res = search(nums, target);
    cout << res;

}