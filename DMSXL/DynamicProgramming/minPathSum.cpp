
//
// Created by Yao on 2023/10/18.
// Description:     
//

/*
 * 给定一个 n*m 的二维网格grid，网格中的每个单元格包含一个非负整数，
 * 表示该单元格的代价。机器人以左上角单元格为起始点，每次只能向下或者向右移动一步，
 * 直至到达右下角单元格。请返回从左上角到右下角的最小路径和。
 */
#include <iostream>
#include<vector>
using namespace std;

int minPathSumDP(vector<vector<int>> & grid){
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

    dp[0][0] = grid[0][0];

    for (int i = 1; i < dp.size(); ++i) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for (int j = 1; j < dp[0].size(); ++j) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j < dp[0].size(); ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    return dp[dp.size()-1][dp[0].size()-1];
}

int main() {

    vector<vector<int>> grid = {{1,3,1,5},{2,2,4,2},{5,3,2,1},{4,3,5,2}};

    int res = minPathSumDP(grid);

    cout << res << endl;

}
