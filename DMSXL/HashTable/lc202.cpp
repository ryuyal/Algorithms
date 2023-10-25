//
// Created by Liu on 2023/7/6.
// Description:
//

#include <iostream>
#include <unordered_set>
using namespace std;
int sumOfSquare(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int temp = n % 10;
        sum += temp * temp;
        n /= 10;
    }
    return sum;
}
bool isHappy(int n)
{
    unordered_set<int> set;

    set.insert(n);
    while (n != 1)
    {
        n = sumOfSquare(n);
        if (set.count(n) != 0)
        {
            return false;
        }
        set.insert(n);
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    bool res = isHappy(n);
    cout << res << endl;
}
