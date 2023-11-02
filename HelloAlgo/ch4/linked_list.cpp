
//
// Created by Yao on 2023/11/2.
// Description:
//

#include <iostream>
using namespace std;

/* 链表节点结构体 */
struct ListNode {
    int val;         // 节点值
    ListNode *next;  // 指向下一节点的指针
    ListNode(int x) : val(x), next(nullptr) {}  // 构造函数
};

/* 在链表的节点 n0 之后插入节点 P */
void insert(ListNode *n0, ListNode *P) {
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

/* 删除链表的节点 n0 之后的首个节点 */
void remove(ListNode *n0) {
    if (n0->next == nullptr)
        return;
    // n0 -> P -> n1
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    // 释放内存
    delete P;
}

/* 访问链表中索引为 index 的节点 */
ListNode *access(ListNode *head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}


/* 在链表中查找值为 target 的首个节点 */
int find(ListNode *head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

void printLinkedList(ListNode * head){
    ListNode * dummy = head;
    while(dummy != nullptr){
        if(dummy ->next != nullptr)
        {
            cout << dummy->val << "->";
        }else{
            cout << dummy->val << endl;
        }
        dummy = dummy->next;
    }
}

int main()
{
    /* 初始化链表 1 -> 3 -> 2 -> 5 -> 4 */
    // 初始化各个节点
    ListNode* n0 = new ListNode(1);
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(5);
    ListNode* n4 = new ListNode(4);
    // 构建引用指向
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    printLinkedList(n0);

    ListNode* insertNode = new ListNode(8);
    insert(n3, insertNode);
    printLinkedList(n0);

    remove(n2);
    printLinkedList(n0);

    ListNode * getNode = access(n0,3);
    cout << "Index 3 = " << getNode->val << endl;

    int getIndex = find(n0, 8);
    cout << "The index of 8 is " << getIndex << endl;

}
