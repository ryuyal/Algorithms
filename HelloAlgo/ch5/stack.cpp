
//
// Created by Yao on 2023/11/3.
// Description:
//

#include <iostream>
#include<stack>
using namespace std;

int main()
{
    /* 初始化栈 */
    stack<int> stack;

    /* 元素入栈 */
    stack.push(1);
    stack.push(3);
    stack.push(2);
    stack.push(5);
    stack.push(4);

    /* 访问栈顶元素 */
    int top = stack.top();
    cout << top << endl;

    /* 元素出栈 */
    stack.pop(); // 无返回值

    /* 获取栈的长度 */
    int size = stack.size();
    cout << size << endl;

    /* 判断是否为空 */
    bool empty = stack.empty();
    cout << empty << endl;
}
