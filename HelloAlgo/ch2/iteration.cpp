
//
// Created by Yao on 2023/11/1.
// Description:
//

#include <iostream>
using namespace std;

/* for 循环 */
int forLoop(int n)
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res += i;
    }

    return res;
}

/* while 循环 */
int whileLoop(int n)
{
    int res = 0;
    int i = 1;
    while (i <= n)
    {
        res += i;
        i++;
    }
    return res;
}

/* while 循环（两次更新） */
int whileLoopII(int n) {
    int res = 0;
    int i = 1; // 初始化条件变量
    // 循环求和 1, 4, ...
    while (i <= n) {
        res += i;
        // 更新条件变量
        i++;
        i *= 2;
    }
    return res;
}

int main()
{
    int n = 10;

    cout << forLoop(n) << endl;
    cout << whileLoop(n) << endl;
    cout << whileLoopII(n) << endl;
}
