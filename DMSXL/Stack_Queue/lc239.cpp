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
/*

 pop(value)：如果窗口移除的元素value等于单调队列的出口元素，
 那么队列弹出元素，否则不用任何操作

 push(value)：如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，
 直到push元素的数值小于等于队列入口元素的数值为止
 */
//class MyQueue{
//public:
//    deque<int> que; // 使用deque实现单调队列
//
//    void pop(int val){
//        if(!que.empty() && val == que.front()){
//            que.pop_front();
//        }
//    }
//
//    void push(int val){
//        while(!que.empty() && val > que.back()){
//            que.pop_back();
//        }
//
//        que.push_back(val);
//    }
//
//    int front(){
//        return que.front();
//    }
//};
//
//vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//    MyQueue que;
//
//    vector<int> res;
//
//    for(int i = 0; i < k; ++i){
//        que.push(nums[i]);
//    }
//
//    res.push_back(que.front());
//
//    for(int i = k; i < nums.size(); ++i){
//        que.pop(nums[i-k]);
//        que.push(nums[i]);
//
//        res.push_back(que.front());
//    }
//
//    return res;
//
//}

// 单调队列
class MonotonicQueue{
public:
    void push(int val){
        while(!que.empty() && val > que.back()){
            que.pop_back();
        }

        que.push_back(val);
    }

    void pop(int val){
        if (!que.empty() && val == que.front()){
            que.pop_front();
        }
    }

    int front(){
        return que.front();
    }

private:
    deque<int> que;
};

vector<int> maxSlidingWindow(vector<int> & nums, int k){
    MonotonicQueue mQueue;

    vector<int> res;

    for(int i = 0; i < k; ++i){
        mQueue.push(nums[i]);
    }

    res.push_back(mQueue.front());

    for(int i = k; i < nums.size(); ++i){
        mQueue.pop(nums[i-k]);
        mQueue.push(nums[i]);

        res.push_back(mQueue.front());
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
