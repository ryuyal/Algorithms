//
// Created by Liu on 2023/6/7.
//

#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
    {
        return "";
    }
    if (strs.size() == 1)
    {
        return strs[0];
    }

    string pre_str = strs[0];
    for (int i = 0; i < pre_str.length(); ++i)
    {
        for (int j = 1; j < strs.size(); ++j)
        {
            string tmp = strs[j];
            if (tmp.length() <= i || tmp[i] != pre_str[i])
            {
                return pre_str.substr(0, i);
            }
        }
    }
    return pre_str;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    string res = longestCommonPrefix(strs);
    cout << res;
}