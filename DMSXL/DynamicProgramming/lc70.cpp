//
// Created by Liu on 2023/7/28.
// Description:
//

#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }

    int res = 0;
    int n1 = 1;
    int n2 = 2;
    for (int i = 3; i <= n; ++i)
    {
        res = n1 + n2;
        n1 = n2;
        n2 = res;
    }

    return res;
}

//// 超时
// int climbStairs2(int n) {
//     if(n <= 2){
//         return n;
//     }
//
//     return climbStairs(n-2) + climbStairs(n-1);
//
// }

/*
 * 记忆化搜索
 */

int dfs(int i, vector<int> &mem)
{
    if (i == 1 || i == 2)
    {
        return i;
    }
    if (mem[i] != -1)
    {
        return mem[i];
    }

    int count = dfs(i - 1, mem) + dfs(i - 2, mem);
    mem[i] = count;

    return count;
}

int climbStairsDFSMem(int n)
{
    vector<int> mem(n + 1, -1);

    return dfs(n, mem);
}

int main()
{
    cout << climbStairs(3) << endl;
}
