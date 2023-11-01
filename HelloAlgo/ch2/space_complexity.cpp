
//
// Created by Yao on 2023/11/1.
// Description:
//

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/* 结构体 */
struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(nullptr){}
};

/* 函数 */
int func() {
    // 执行某些操作
    return 0;
}

/* 常数阶 */
void constant(int n) {
    // 常量、变量、对象占用 O(1) 空间
    const int a = 0;
    int b = 0;
    vector<int> nums(10000);
    ListNode node(0);
    // 循环中的变量占用 O(1) 空间
    for (int i = 0; i < n; i++) {
        int c = 0;
    }
    // 循环中的函数占用 O(1) 空间
    for (int i = 0; i < n; i++) {
        func();
    }
}

/* 线性阶 */
void linear(int n) {
    // 长度为 n 的数组占用 O(n) 空间
    vector<int> nums(n);
    // 长度为 n 的列表占用 O(n) 空间
    vector<ListNode> nodes;
    for (int i = 0; i < n; i++) {
        nodes.emplace_back(ListNode(i));
    }
    // 长度为 n 的哈希表占用 O(n) 空间
    unordered_map<int, string> map;
    for (int i = 0; i < n; i++) {
        map[i] = to_string(i);
    }
}

int main()
{

}
