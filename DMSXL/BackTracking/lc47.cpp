
//
// Created by Yao on 2023/10/13.
// Description:     
//

#include <iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

/*
 * 方法一：使用set去重
 */
/*vector<vector<int>> res;
vector<int> path;

void dfs(vector<int> & nums, vector<bool> & used){
    if(path.size() == nums.size()){
        res.push_back(path);
        return ;
    }

    unordered_set<int> uset; // 记录本层中用过的元素
    for(int i = 0; i < nums.size(); ++i){

        if (used[i] || uset.find(nums[i])!=uset.end()){
            continue;
        }
        uset.insert(nums[i]);

        used[i] = true;
        path.push_back(nums[i]);
        dfs(nums, used);
        path.pop_back();
        used[i] = false;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<bool> used(nums.size(), false);

    dfs(nums, used);

    return res;
}
}*/

/*
 * 方法二：使用used去重
 */
vector<vector<int>> res;
vector<int> path;

void dfs(vector<int> & nums, vector<bool> & used){
    if (path.size() == nums.size()){
        res.push_back(path);
        return ;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if(used[i]){
            continue;
        }
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]){
            continue;
        }
        used[i] = true;
        path.push_back(nums[i]);
        dfs(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<bool> used(nums.size(), false);

    dfs(nums, used);

    return res;
}

int main() {
    vector<int> nums{1,1,2};
    auto res = permuteUnique(nums);

    for(auto v : res){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}
