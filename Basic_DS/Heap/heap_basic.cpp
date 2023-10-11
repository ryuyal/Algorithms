
//
// Created by Yao on 2023/10/11.
// Description:     
//

#include <iostream>
#include<queue>
using namespace std;

/*
 *  priority_queue<Type, Container, Functional>
 *  Type为数据类型，Container为保存数据的容器，Functional为元素比较方式
 *  如果不写后两个参数，那么容器默认用的是vector，比较方式默认用operator<，
 *  也就是优先队列是大顶堆，队头元素最大。
 */
int main() {
//    priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆
    priority_queue<int, vector<int>, less<int>> maxHeap; // 大顶堆

    maxHeap.push(1);
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(4);

    int peek = maxHeap.top();
    cout << "maxHeap top element = " << peek << endl;

    maxHeap.pop(); // 5
    maxHeap.pop(); // 4
    maxHeap.pop(); // 3
    maxHeap.pop(); // 2
    maxHeap.pop(); // 1

    int size = maxHeap.size();
    cout << "maxHeap size = " << size << endl;

    bool isEmpty = maxHeap.empty() ;
    cout << "Is maxHeap empty? " << (isEmpty == 1 ? "Yes" : "No") << endl;

    vector<int> input{1, 3, 2, 5, 4};
    priority_queue<int, vector<int>, greater<int>> minHeap(input.begin(), input.end());
    cout << "minHeap top element = " << minHeap.top() << endl;
}
