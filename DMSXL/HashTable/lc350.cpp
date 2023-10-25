//
// Created by Liu on 2023/7/6.
// Description:
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> map;

    for (int val : nums1)
    {
        ++map[val];
    }

    vector<int> res;
    for (int val : nums2)
    {
        if (map[val] > 0)
        {
            res.push_back(val);
            --map[val];
        }
    }
    return res;
}

int main()
{
}
