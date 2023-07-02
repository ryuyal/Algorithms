//
// Created by Liu on 2023/7/2.
// Description: 
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int totalFruit(vector<int> & nums){
    int left = 0;
    int right = 0;
    int len = 0;

    unordered_map<int, int> uMap; // uMap 存储nums[i]及其个数

    for (; right < nums.size(); ++right) {
        ++uMap[nums[right]];

        while(uMap.size() > 2){ // 不满足条件
            uMap[nums[left]]--;
            if (uMap[nums[left]] == 0){
                uMap.erase(nums[left]);
            }

            ++left;
        }

        len = max(len, right - left + 1);
    }
    return len;
}

int main() {
    int n;
    cout <<  "Please input the number of elements: " <<  endl;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int res = totalFruit(nums);
    cout << res;
}
