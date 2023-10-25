//
// Created by Liu on 2023/7/4.
// Description:
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

// 1. 快慢指针法
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    //    https://leetcode.cn/problems/linked-list-cycle-ii/solutions/12616/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
    /*
     * 设链表共有 a+b 个节点，其中 链表头部到链表入口 有 a
    个节点（不计链表入口节点）， 链表环有 b 个节点（这里需要注意，a 和 b
    是未知数，设两指针分别走了 f，s 步，则有： fast 走的步数是 slow 步数的 2
    倍，即 f=2s；（解析： fast 每轮走 2 步） fast 比 slow 多走了 n 个环的长度，即
    f=s+nb；（ 解析： 双指针都走过 a 步，然后在环内绕圈直到重合，重合时 fast 比
    slow 多走 环的长度整数倍 ）。 将以上两式相减得到 f=2nb，s=nb，即 fast 和 slow
    指针分别走了 2n，n个环的周长。

    接下来fast从head开始走，走a步之后到达链表环的入口，总共走了a+2nb步
     */
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) //
        {
            fast = head;
            while (slow != nullptr && fast != nullptr)
            {
                if (slow == fast)
                {
                    return slow;
                }
                slow = slow->next;
                fast = fast->next;
            }
        }
    }
    return nullptr;
}

// 2. 集合法，用HashSet保存结点

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

    ListNode *preHead = new ListNode();
    ListNode *pre = preHead;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        pre->next = new ListNode(val);
        pre = pre->next;
    }

    show(preHead->next);

    ListNode *res = detectCycle(preHead->next);
    show(res);
}
