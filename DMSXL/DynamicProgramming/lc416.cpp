
//
// Created by Yao on 2023/10/17.
// Description:     
//

#include <iostream>
#include<vector>
using namespace std;

/*
 * 是否可以从输入数组中挑选出一些正整数，使得这些数的和等于整个数组元素的和的一半
 */
bool canPartition(vector<int>& nums) {
    //dp[j]表示 背包总容量（所能装的总重量）是j，放进物品后，背的最大重量为dp[j]
    // 背包容量为 target 则dp[target]就是装满背包之后的重量 当dp[target]== target时 背包就装满了

    /*
     * 物品是nums[i]，重量是nums[i]，价值也是nums[i]，背包体积是sum/2。
     */
    vector<int> dp(10001, 0);
    int sum = 0;
    for (auto i : nums) {
        sum += i;
    }
    if(sum % 2 == 1){
        return false;
    }

    int target = sum / 2;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = target; j >=nums[i] ; --j) {
            dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
        }
    }

    if (dp[target] == target){
        return true;
    }

    return false;

}

int main() {

}
