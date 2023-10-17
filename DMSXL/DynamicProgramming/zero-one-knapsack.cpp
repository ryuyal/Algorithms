
//
// Created by Yao on 2023/10/17.
// Description:     
//

#include <iostream>
#include<vector>
using namespace std;

/*
 * 例子： 3个物品 重量分别为：1  3  4
 *             价值分别为：15 20 30
 *      背包最大重量为 4
 */

// dp[i][j] 表示从下标为[0-i]的物品里任意取，
// 放进容量为j的背包，价值总和最大是多少

/*
 * 两个方向可以推导出dp[i][j]：
 *
 * 不放物品i：由dp[i - 1][j]推出，即背包容量为j，里面不放物品i的最大价值，
 * 此时dp[i][j]就是dp[i - 1][j]。(其实就是当物品i的重量大于背包j的重量时，
 * 物品i无法放进背包中，所以背包内的价值依然和前面相同。)
 *
 * 放物品i：由dp[i - 1][j - weight[i]]推出，
 * dp[i - 1][j - weight[i]]为背包容量为j - weight[i]的时候不放物品i的最大价值，
 * 那么dp[i - 1][j - weight[i]] + value[i]
 * （物品i的价值），就是背包放物品i得到的最大价值
 */

void bag_problem1(){
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};

    int bagweight = 4;

    vector<vector<int>> dp(weight.size(), vector<int>(bagweight+1, 0));

    // 初始化 ！！！ important
    for(int j = weight[0]; j < bagweight+1; ++j){
        dp[0][j] = value[0];
    }

    for(int i = 1; i < weight.size(); ++i){
        for (int j = 0; j < bagweight+1 ; ++j) {
            if(j < weight[i]){
                // 当前背包的容量都没有当前物品i大的时候，是不放物品i的
                // 那么前i-1个物品能放下的最大价值就是当前情况的最大价值
                dp[i][j] = dp[i-1][j];
            }else {
//                * 当前背包的容量可以放下物品i
//                * 那么此时分两种情况：
//                *    1、不放物品i
//                *    2、放物品i
//                * 比较这两种情况下，哪种背包中物品的最大价值最大
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    cout << dp[weight.size()-1][bagweight] << endl;

}

int main() {

    bag_problem1();

    return 0;

}
