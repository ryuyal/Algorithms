//
// Created by Liu on 2023/7/29.
// Description: 
//

#include <iostream>
#include<vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size()+1);

    // dp[i]中的i代表登上第i级台阶，最终i=cost.size()
    dp[0] = 0;
    dp[1] = 0;

    /*
     * dp[i - 1] 跳到 dp[i] 需要花费 dp[i - 1] + cost[i - 1]
     * dp[i - 2] 跳到 dp[i] 需要花费 dp[i - 2] + cost[i - 2]
     */
    for(int i = 2; i <= cost.size(); ++i){
        dp[i] =  min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }

    return dp[cost.size()];
}

int main() {

    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};

    int res = minCostClimbingStairs(cost);

    cout << res << endl;

}
