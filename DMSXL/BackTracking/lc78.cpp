
//
// Created by Yao on 2023/10/12.
// Description:     
//

#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtracking(vector<int> & nums, int startIndex){
    // 或者直接把收集子集放在终止添加的上面，否则会漏掉自己
    // res.push_back(path);
    if(startIndex >= nums.size()){
        return ;
    }

    for(int i = startIndex; i < nums.size(); ++i){
        path.push_back(nums[i]);
        res.push_back(path);
        backtracking(nums, i+1);

        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    res.push_back(path); // 空集也是子集

    backtracking(nums, 0);

    return res;
}

int main() {

    vector<int> nums{1,2,3};

    auto res = subsets(nums);

    for(auto v : res){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }

}
