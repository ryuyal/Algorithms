//
// Created by Liu on 2023/7/5.
// Description: 
//

#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    unordered_set<int> set;
    for (int num : nums1) {
        set.insert(num);
    }

    for(int num : nums2){
        if (set.count(num) > 0){
            set.erase(num);
            res.push_back(num);
        }
    }
    return res;
}

int main() {

}
