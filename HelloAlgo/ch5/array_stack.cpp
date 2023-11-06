
//
// Created by Yao on 2023/11/3.
// Description:
//

#include <iostream>
#include<vector>
using namespace std;

/* 基于数组实现的栈 */
class ArrayStack {
  private:
    vector<int> stack;

  public:
    /* 获取栈的长度 */
    int size() {
        return stack.size();
    }

    /* 判断栈是否为空 */
    bool isEmpty() {
        return stack.size() == 0;
    }

    /* 入栈 */
    void push(int num) {
        stack.push_back(num);
    }

    /* 出栈 */
    void pop() {
        int oldTop = top();
        stack.pop_back();
    }

    /* 访问栈顶元素 */
    int top() {
        if (isEmpty())
            throw out_of_range("EMPTY");
        return stack.back();
    }

    /* 返回 Vector */
    vector<int> toVector() {
        return stack;
    }
};

void printVector(vector<int> & nums){
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    ArrayStack * stack = new ArrayStack();

    stack->push(1);
    stack->push(3);
    stack->push(2);
    stack->push(5);
    stack->push(4);

    vector<int> a = stack->toVector();

    printVector(a);

    /* 访问栈顶元素 */
    int top = stack->top();
    cout << "top = " << top << endl;

    /* 元素出栈 */
    stack->pop();
    cout << "pop = " << top << " stack = ";
    a = stack->toVector();
    printVector(a);

    /* 获取栈的长度 */
    int size = stack->size();
    cout << "size = " << size << endl;

    /* 判断是否为空 */
    bool empty = stack->isEmpty();
    cout << "empty = " << empty << endl;

    // 释放内存
    delete stack;
}
