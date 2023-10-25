//
// Created by Liu on 2023/7/30.
// Description:
//

#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 1; i < n; ++i)
    {
        dp[0][i] = 1;
    }

    for (int i = 0; i < m; ++i)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{

    //    int res = uniquePaths(1, 1);
    int res = uniquePaths(3, 7);
    cout << res << endl;
}
