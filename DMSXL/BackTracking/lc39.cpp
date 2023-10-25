//
// Created by Liu on 2023/7/27.
// Description:
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;
int sum = 0;

void backtracking(vector<int> &candidates, int target, int startIndex)
{
    if (sum > target)
    {
        return;
    }

    if (sum == target)
    {
        result.push_back(path);
        return;
    }

    for (int i = startIndex; i < candidates.size(); ++i)
    {
        sum += candidates[i];
        path.push_back(candidates[i]);
        backtracking(candidates, target, i);
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    backtracking(candidates, target, 0);

    return result;
}

int main()
{
}
