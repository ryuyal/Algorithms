//
// Created by Liu on 2023/7/11.
// Description:
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isOp(string s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/")
    {
        return true;
    }

    return false;
}

int calculate(int ch1, int ch2, string op)
{
    if (op == "+")
    {
        return ch1 + ch2;
    }
    if (op == "-")
    {
        return ch2 - ch1;
    }
    if (op == "*")
    {
        return ch1 * ch2;
    }
    else
    {
        return ch2 / ch1;
    }
}

int evalRPN(vector<string> &tokens)
{
    stack<int> stk;
    int res = 0;
    for (string s : tokens)
    {
        if (isOp(s))
        {
            int ch1 = stk.top();
            stk.pop();
            int ch2 = stk.top();
            stk.pop();

            res = calculate(ch1, ch2, s);
            stk.push(res);
        }
        else
        {
            stk.push(stoi(s));
        }
    }
    return stk.top();
}

int main()
{
}
