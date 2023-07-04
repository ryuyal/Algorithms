//
// Created by Liu on 2023/7/4.
// Description: 
//

#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode * next;

    ListNode(){}
    ListNode(int v):val(v), next(nullptr){}
    ListNode(int v, ListNode * n):val(v), next(n){}
};

ListNode *detectCycle(ListNode *head) {
    ListNode * slow = head;
    ListNode * fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            fast = head;
            while(slow != nullptr && fast != nullptr){
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

void show(ListNode * head){
    ListNode * cur = head;
    while(cur != nullptr){
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    ListNode * preHead = new ListNode();
    ListNode * pre = preHead;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        pre->next = new ListNode(val);
        pre = pre->next;
    }

    show(preHead->next);


    ListNode * res = detectCycle(preHead->next);
    show(res);
}
