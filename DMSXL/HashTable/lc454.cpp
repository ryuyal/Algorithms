//
// Created by Liu on 2023/7/6.
// Description:
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 分成2组
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    vector<int> nums12(nums1.size() * nums2.size());

    vector<int> nums34(nums3.size() * nums4.size());

    int i = 0;
    for (auto val1 : nums1)
    {
        for (auto val2 : nums2)
        {
            nums12[i++] = val1 + val2;
        }
    }

    i = 0;
    for (auto val3 : nums3)
    {
        for (auto val4 : nums4)
        {
            nums34[i++] = val3 + val4;
        }
    }

    int res = 0;
    unordered_map<int, int> map;
    for (auto val : nums12)
    {
        ++map[val];
    }

    for (auto val : nums34)
    {
        if (map[-val] != 0)
        {
            res += map[-val];
        }
    }

    return res;
}

// 1124
int fourSumCount2(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

    unordered_map<int, int> map1;
    for(auto num1 : nums1){
        for(auto num2 : nums2){
            ++map1[num1 + num2];
        }
    }

    unordered_map<int, int> map2;
    for(auto num1 : nums3){
        for(auto num2 : nums4){
            ++map2[num1 + num2];
        }
    }

    int res = 0;
    for(auto pair1 : map1){
        for(auto pair2 : map2){
            if(pair1.first == -pair2.first){
                res += pair1.second * pair2.second;
            }
        }
    }
    return res;
}

int main()
{
}
