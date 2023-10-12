
//
// Created by Yao on 2023/10/12.
// Description:     
//

#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;

void dfs(vector<int> & nums, vector<bool> & used){
    if(path.size() == nums.size()){
        res.push_back(path);
        return ;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if(used[i] == true){
            continue;
        }
        used[i] = true;
        path.push_back(nums[i]);
        dfs(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);

    dfs(nums, used);

    return res;
}

int main() {

}
