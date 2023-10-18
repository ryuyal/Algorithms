
//
// Created by Yao on 2023/10/18.
// Description:     
//

#include <iostream>
#include <vector>
using namespace std;

//给定一个共有n阶的楼梯，你每步可以上1阶或者2阶，但不能连续两轮跳1阶，请问有多少种方案可以爬到楼顶。

int climbStairsWithConstraintDP(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    vector<vector<int>> dp(n+1, vector<int>(3,0));
    // 状态[i,j]表示处在第i阶、并且上一轮跳了j阶 j∈{1,2}
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;

    // dp[i,j]代表状态[i,j]对应的方案数

    for (int i = 3; i < n+1; ++i) {
        dp[i][1] = dp[i-1][2];
        dp[i][2] = dp[i-2][1] + dp[i-2][1];
    }

    return dp[n][1] + dp[n][2];
}

int main() {

    int n = 5;
    int res = climbStairsWithConstraintDP(n);

    std::cout << res << std::endl;

}
