
//
// Created by Yao on 2023/10/19.
// Description:     
//

#include <iostream>
#include<vector>
using namespace std;

/*
 *  例子
 *  5个物品: 重量分别为：10  20  30  40  50
 *          价值分别为：50 120 150 210 240
 *      背包容量为 50
 *
 *      可以重复选取，求不超过背包容量下能放入的最大价值
 */

int unboundedKnapSack(vector<int> & weights, vector<int> & values, int capacity){

    vector<vector<int>> dp(weights.size(), vector<int>(capacity+1,0));

    /*
     * 要初始化！！！第一行
     */
    for(int j = weights[0]; j < capacity+1; ++j){
        dp[0][j] = values[0];
    }

    // 这里 i 从 1 开始！！！（i从0开始的话，i-1会超出下标范围）
    for (int i = 1; i < weights.size(); ++i) {
        for (int j = 0; j < capacity+1; ++j) {
            if(j < weights[i]){ // 不拿物品i
                dp[i][j] = dp[i-1][j];
            }else{ // 比较拿与不拿，选取更大的
                dp[i][j] = max(dp[i-1][j], dp[i][j-weights[i]] + values[i]);
            }
        }
    }

    return dp[weights.size()-1][capacity];
}

int unboundedKnapSack2(vector<int> & weights, vector<int> & values, int capacity){

    vector<int> dp(capacity+1,0);

    /*
     * 要初始化！！！第一行
     */

    // 这里 i 从 1 开始！！！（i从0开始的话，i-1会超出下标范围）
    for (int i = 0; i < weights.size(); ++i) {
        for (int j = 0; j < capacity+1; ++j) {
            if(j < weights[i]){ // 不拿物品i
                dp[j] = dp[j];
            }else{ // 比较拿与不拿，选取更大的
                dp[j] = max(dp[j], dp[j-weights[i]] + values[i]);
            }
        }
    }

    return dp[capacity];
}

int main() {

    vector<int> weights {10, 20, 30, 40, 50};
    vector<int> values {50, 120, 150, 210, 240};
    int capacity = 50;

    int res = unboundedKnapSack(weights, values, capacity);
    cout << "aa " << res << endl;

    res = unboundedKnapSack2(weights, values, capacity);
    cout << "bb " << res << endl;

    return 0;
}
