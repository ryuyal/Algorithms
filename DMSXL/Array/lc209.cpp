//
// Created by Liu on 2023/7/2.
// Description: 
//

#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> & nums){
    int left = 0;
    int sum = 0;
    int len = 0;
    int res = nums.size()+1;

    for (int right = 0; right < nums.size(); ++right) { // i 代表滑动窗口的终止位置
        sum += nums[right];

        while(sum >= target){
            len = right - left + 1;
            res = res < len ? res : len;// 更新结果

            sum -= nums[left++]; // 减去左边的元素
        }
    }
    return res == nums.size()+1 ? 0 : res;
}

int main() {
    int target;
    cout << "Please input the value of target:" << endl;
    cin >> target;

    int n;
    cout << "Please input the number of elements: " << endl;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        nums[i] = val;
    }

    int res = minSubArrayLen(target, nums);
    cout << res;
}
