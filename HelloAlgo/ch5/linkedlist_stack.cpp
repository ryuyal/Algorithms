
//
// Created by Yao on 2023/11/3.
// Description: 基于链表实现栈
//

#include <iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int v) : val(v), next(nullptr){}
};

class LinkedListStack
{
  private:
    ListNode *stackTop; // 头节点作为栈顶
    int stackSize;

  public:
    LinkedListStack(){
        stackSize = 0;
        stackTop = nullptr;
    }

    ~LinkedListStack(){
        freeMemoryLinkedList(stackTop);
    }

    void freeMemoryLinkedList(ListNode * cur){
        ListNode * pre;
        while(cur != nullptr){
            pre = cur;
            cur = cur->next;
            delete pre;
        }
    }

    /* 获取栈的长度 */
    int size() {
        return stackSize;
    }

    bool isEmpty(){
        return stackSize == 0;
    }

    /* 入栈 */
    void push(int num) {
        ListNode *node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stackSize++;
    }

    /* 出栈 */
    void pop() {
        int num = top();
        ListNode *tmp = stackTop;
        stackTop = stackTop->next;
        // 释放内存
        delete tmp;
        stackSize--;
    }

    /* 访问栈顶元素 */
    int top() {
        if (isEmpty())
            throw out_of_range("栈为空");
        return stackTop->val;
    }

    vector<int> toVector(){
        ListNode *node = stackTop;
        vector<int> res(size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
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
    LinkedListStack * stack = new LinkedListStack();

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
