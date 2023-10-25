//
// Created by Liu on 2023/7/11.
// Description:
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/*vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> uMap;

    for(auto val : nums){
        uMap[val]++;
    }

    // C++ 中默认为大顶堆
    priority_queue<pair<int,int>> pq;

    for(auto it : uMap){
        *//*
        // 把uMap中的value作为pair的第一个元素
        （priority_queue中默认排序按照 key）
        *//*
        pq.emplace(it.second, it.first); // 把uMap中的value作为pair的第一个元素（priority_queue中默认排序）
    }

    vector<int> res;
    while(k){
        res.push_back(pq.top().second);
        pq.pop();
        --k;
    }

    return res;
}*/

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> uMap;
    for (int val : nums)
    {
        uMap[val]++;
    }

    priority_queue<pair<int, int>> pq;

    for (auto it : uMap)
    {
        //        pq.emplace(it.second, it.first); // as same as below
        pq.push(pair(it.second, it.first));
    }

    vector<int> res;

    for (int i = 0; i < k; ++i)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}

int main()
{
    int n;
    cout << "Please input the number of elements: " << endl;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    int k;
    cout << "Please input k: " << endl;
    cin >> k;

    vector<int> res = topKFrequent(nums, k);

    for (auto v : res)
    {
        cout << v << " ";
    }
}