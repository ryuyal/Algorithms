
//
// Created by Yao on 2023/11/3.
// Description:
//

#include <iostream>
#include<queue>
using namespace std;

int main()
{
    /* 初始化队列 */
    queue<int> queue;

    /* 元素入队 */
    queue.push(1);
    queue.push(3);
    queue.push(2);
    queue.push(5);
    queue.push(4);

    /* 访问队首元素 */
    int front = queue.front();
    cout << front << endl;

    /* 元素出队 */
    queue.pop();

    /* 获取队列的长度 */
    int size = queue.size();
    cout << size << endl;

    /* 判断队列是否为空 */
    bool empty = queue.empty();
    cout << empty << endl;

}
