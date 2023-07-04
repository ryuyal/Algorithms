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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode * dummy = new ListNode(0, head);
    ListNode * cur = dummy->next;
    for (int i = 0; i < n; i++)
    {
        cur = cur->next;
    }

    ListNode * pre = dummy;
    while(cur != nullptr ){
        pre = pre->next;
        cur = cur->next;
    }

    pre->next = pre->next->next;

    return dummy->next;
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

    int k;
    cin >> k;
    ListNode * res = removeNthFromEnd(preHead->next, k);
    show(res);
}
