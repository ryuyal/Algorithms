//
// Created by Liu on 2023/6/3.
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
    ListNode(int val) : val(val), next(nullptr)
    {
    }
    ListNode(int val, ListNode *next) : val(val), next(next)
    {
    }
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *newHead = new ListNode(0, head);

    ListNode *cur = head;
    for (int i = 0; i < n; ++i)
    {
        cur = cur->next;
    }

    ListNode *pre = newHead;
    while (cur != nullptr)
    {
        pre = pre->next;
        cur = cur->next;
    }

    pre->next = pre->next->next;

    return newHead->next;
}

void printList(ListNode *head)
{
    ListNode *p = head;
    while (p != nullptr)
    {
        if (p->next != nullptr)
        {
            cout << p->val << "->";
        }
        else
        {
            cout << p->val;
        }
        p = p->next;
    }
    cout << endl;
}

int main()
{

    ListNode *pre = new ListNode();
    ListNode *head = pre;

    int num;
    while (cin >> num)
    {
        ListNode *cur = new ListNode(num);
        pre->next = cur;
        pre = pre->next;
        char ch = getchar();
        if (ch == '\n')
        {
            break;
        }
    }
    printList(head->next);

    int n;
    cin >> n;

    ListNode *res = removeNthFromEnd(head->next, n);

    printList(res);
}