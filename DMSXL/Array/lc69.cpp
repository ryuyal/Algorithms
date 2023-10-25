//
// Created by Liu on 2023/6/30.
//

#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    if (x == 2)
    {
        return 1;
    }

    long left = -1;
    long right = x;

    while (left + 1 != right)
    {
        long mid = left + (right - left) / 2;

        if (x / mid == mid)
        { // 这里不要用 mid * mid  防止整数溢出
            return mid;
        }
        else if (x / mid > mid)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

int main()
{
    int x;
    cin >> x;

    int res = mySqrt(x);

    cout << res;
}
