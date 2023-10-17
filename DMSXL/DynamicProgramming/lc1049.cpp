
//
// Created by Yao on 2023/10/17.
// Description:     
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lastStoneWeightII(vector<int>& stones) {
    // dp[j]表示容量（这里说容量更形象，其实就是重量）为j的背包，最多可以背最大重量为dp[j]
    int sum = 0;
    for(auto i : stones){
        sum += i;
    }

    int target = sum / 2;
    vector<int> dp(target, 0);

    for (int i = 0; i < stones.size(); ++i) {
        for (int j = target; j >= stones[i] ; --j) {
            dp[i] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }

    return sum - dp[target] - dp[target];
}

int main() {

}
