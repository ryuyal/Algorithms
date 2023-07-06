//
// Created by Liu on 2023/7/6.
// Description: 
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 分成2组
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    vector<int> nums12(nums1.size() * nums2.size());

    vector<int> nums34(nums3.size() * nums4.size());

    int i = 0;
    for(auto val1 : nums1){
        for(auto val2 : nums2){
            nums12[i++] = val1 + val2;
        }
    }

    i = 0;
    for(auto val3 : nums3){
        for(auto val4 : nums4){
            nums34[i++] = val3 + val4;
        }
    }

    int res = 0;
    unordered_map<int, int> map;
    for(auto val : nums12)
    {
        ++map[val];
    }

    for(auto val : nums34){
        if(map[-val] != 0){
            res += map[-val];
        }
    }

    return res;
}

int main() {

}
