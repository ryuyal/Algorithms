//
// Created by Liu on 2023/6/5.
//
#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int cur = 0;
    int num = x;
    while (num != 0)
    {
        cur = cur * 10 + num % 10;
        num /= 10;
    }
    return cur == x;
}

int main()
{
    int num;
    cin >> num;

    bool res = isPalindrome(num);
    cout << res << endl;
}
