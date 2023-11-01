
//
// Created by Yao on 2023/11/1.
// Description:
//

#include <iostream>
#include<stack>
using namespace std;

/* 递归 */
int recur(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int res = recur(n - 1);

    return n + res;
}

/* 尾递归 */
int tailRecur(int n, int res)
{
    if (n == 0)
    {
        return res;
    }
    return tailRecur(n - 1, res + n);
}

/* 斐波那契数列：递归 */
int fib(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }

    int res = fib(n - 1) + fib(n - 2);
    return res;
}

/* 使用迭代模拟递归 */
int forLoopRecur(int n){
    stack<int> stk;

    int res = 0;

    for (int i = n; i > 0 ; --i)
    {
        stk.push(i);
    }

    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }

    return res;
}

int main()
{
    cout << recur(10) << endl;

    cout << tailRecur(10, 0) << endl;

    cout << fib(5) << endl;

    cout << forLoopRecur(10) << endl;
}
