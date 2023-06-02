//
// Created by Liu on 2023/6/2.
//
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> um;

    for (int i = 0; i < nums.size(); ++i) {
        if (um.count(target - nums[i]) ==1 ){
            return {um[target-nums[i]], i};
        }

        um[nums[i]] = i;
    }

    return {};
}
int main(){

}