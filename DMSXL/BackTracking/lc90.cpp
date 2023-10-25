
//
// Created by Yao on 2023/10/12.
// Description:
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtracking(vector<int> &nums, int startIndex)
{
    res.push_back(path);
    if (startIndex >= nums.size())
    {
        return;
    }

    for (int i = startIndex; i < nums.size(); ++i)
    {
        if (i > startIndex && nums[i] == nums[i - 1])
        { // 过滤同一层
            continue;
        }

        path.push_back(nums[i]);

        backtracking(nums, i + 1);

        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    backtracking(nums, 0);

    return res;
}

int main()
{

    vector<int> nums{1, 2, 2};

    auto res = subsetsWithDup(nums);

    for (auto v : res)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
