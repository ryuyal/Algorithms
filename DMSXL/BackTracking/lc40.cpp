//
// Created by Liu on 2023/7/27.
// Description:
//

#include <algorithm>
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
        //  // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
        //     // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
        //     // 要对同一树层使用过的元素进行跳过
        // if(i > 0 && candidates[i] == candidates[i-1] && used[i-1]==false){
        //     continue;
        // }
        // 要对同一树层使用过的元素进行跳过
        if (i > startIndex && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        sum += candidates[i];
        path.push_back(candidates[i]);
        // used[i] = true;
        backtracking(candidates, target, i + 1);
        sum -= candidates[i];
        // used[i] = false;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    // backtracking(candidates, target, 0, used);
    backtracking(candidates, target, 0);
    return result;
}

int main()
{
}
