
//
// Created by Yao on 2023/10/13.
// Description:
//

#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n)
{
    vector<int> dp(n + 1); // dp[i]代表分拆数字i, 可以得到的最大乘积为dp[i]

    dp[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        // 从1遍历j
        // j和(i-j)相乘
        // j和dp[i-j]相乘, 这里dp[i-j]相等于拆分(i-j)得到的最大乘积
        for (int j = 1; j <= i / 2; ++j)
        {
            dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        }
    }
    return dp[n];
}

int main()
{
}
