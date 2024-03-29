
//
// Created by Yao on 2023/11/3.
// Description:
//

#include <iostream>
#include<deque>
using namespace std;

int main()
{
    /* 初始化双向队列 */
    deque<int> deque;

    /* 元素入队 */
    deque.push_back(2);   // 添加至队尾
    deque.push_back(5);
    deque.push_back(4);
    deque.push_front(3);  // 添加至队首
    deque.push_front(1);

    /* 访问元素 */
    int front = deque.front(); // 队首元素
    int back = deque.back();   // 队尾元素
    cout << front << endl;
    cout << back << endl;

    /* 元素出队 */
    deque.pop_front();  // 队首元素出队
    deque.pop_back();   // 队尾元素出队
    cout << deque.front() << endl;
    cout << deque.back() << endl;

    /* 获取双向队列的长度 */
    int size = deque.size();
    cout << size << endl;

    /* 判断双向队列是否为空 */
    bool empty = deque.empty();
    cout << empty << endl;
}
