//
// Created by Liu on 2023/7/4.
// Description: 面试题0207
//

#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
    }
    ListNode(int v) : val(v), next(nullptr)
    {
    }
    ListNode(int v, ListNode *n) : val(v), next(n)
    {
    }
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *ha = headA;
    ListNode *hb = headB;

    while (ha != hb)
    {
        ha = ha != nullptr ? ha->next : headB;
        hb = hb != nullptr ? hb->next : headA;
    }

    return ha;
}

int main()
{
}
