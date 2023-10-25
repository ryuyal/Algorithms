//
// Created by Liu on 2023/7/3.
// Description:
//

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *n) : val(x), next(n)
    {
    }
};

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;

    while (cur != nullptr)
    {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

void show(ListNode *head)
{
    ListNode *cur = head;
    while (cur != nullptr)
    {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummyNode = new ListNode();
    ListNode *pre = dummyNode;

    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        ListNode *temp = new ListNode(val);

        pre->next = temp;
        pre = pre->next;
    }

    show(dummyNode->next);

    ListNode *res = reverseList(dummyNode->next);
    show(res);
}
