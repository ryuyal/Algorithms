
//
// Created by Yao on 2023/10/12.
// Description:     
//

#include <iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtracking(vector<int> & nums, int startIndex){
    if(path.size() >=2){
        res.push_back(path);
    }
    if(startIndex >= nums.size()){
        return ;
    }

    unordered_set<int> uset; // 过滤同一层中相同的元素

    for(int i = startIndex; i < nums.size(); ++i){
       if((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()){
           continue;
       }
       uset.insert(nums[i]);
       path.push_back(nums[i]);
       backtracking(nums, i+1);
       path.pop_back();
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {

    backtracking(nums, 0);

    return res;
}


int main() {
    vector<int> nums{4,6,7,7};

    auto res = findSubsequences(nums);

    for(auto v : res){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}
