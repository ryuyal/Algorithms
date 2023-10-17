
//
// Created by Yao on 2023/10/17.
// Description:     
//

#include <iostream>
#include<vector>
using namespace std;

int numTrees(int n) {
    vector<int> dp(n+1); // dp[i] : i个不同元素节点组成的二叉搜索树的个数为dp[i]
    dp[0] = 1;
    if(n < 2){
        return 1;
    }
    dp[1] = 1;
    dp[2] = 2;

    //  dp[i] += dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量]
    //j相当于是头结点的元素，从1遍历到i为止
    for (int i = 3; i < n+1; ++i) {
        for(int j = 1; j <= i; ++j){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }

    return dp[n];
}

int main() {

}
