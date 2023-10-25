//
// Created by Liu on 2023/6/6.
//

#include <iostream>
using namespace std;
int getValue(char ch)
{
    switch (ch)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int romanToInt(string s)
{
    int sum = 0;
    int preNum = getValue(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        int num = getValue(s[i]);
        //            当小值在大值的左边，则减小值，如 IV=5-1=4；
        //            当小值在大值的右边，则加小值，如 VI=5+1=6；
        if (preNum < num)
        {
            sum -= preNum;
        }
        else
        {
            sum += preNum;
        }
        preNum = num;
    }
    sum += preNum;
    return sum;
}

int main()
{
    string s;
    cin >> s;

    int res = romanToInt(s);
    cout << res;
}