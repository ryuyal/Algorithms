//
// Created by Liu on 2023/7/11.
// Description: 
//

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// 单调队列
// 队头 -> 队尾 元素值递减
class MyQueue{
public:
    deque<int> que;

    void pop(int val){
        if(!que.empty() && val == que.front()){
            que.pop_front();
        }
    }

    void push(int val){
        while(!que.empty() && val > que.back()){
            que.pop_back();
        }

        que.push_back(val);
    }

    int front(){
        return que.front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MyQueue que;

    vector<int> res;

    for(int i = 0; i < k; ++i){
        que.push(nums[i]);
    }

    res.push_back(que.front());

    for(int i = k; i < nums.size(); ++i){
        que.pop(nums[i-k]);
        que.push(nums[i]);

        res.push_back(que.front());
    }

    return res;

}

int main(){
    int n;
    cout << "input n:" << endl;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }

    cout << "input k:" << endl;
    int k;
    cin >> k;

    vector<int> res = maxSlidingWindow(nums, k);

    for(int num : res){
        cout << num << " " << endl;
    }
}
