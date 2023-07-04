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

ListNode* swapPairs(ListNode* head) {
    ListNode * dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode * cur = dummyNode;

    while(cur->next != nullptr && cur->next->next != nullptr){
        ListNode * tmp = cur->next;
        ListNode * tmp1 = cur->next->next->next;

        cur->next = cur->next->next;
        cur->next->next = tmp;
        cur->next->next->next = tmp1;

        cur = cur->next->next;
    }
    return dummyNode->next;
}

ListNode * swapPairs2(ListNode * head){
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode * dummyNode = new ListNode(0, head);
    ListNode * pre = dummyNode;
    ListNode * cur = head;
    ListNode * post = cur->next;

    while(cur != nullptr && post != nullptr){
        pre->next = post;
        cur->next = post->next;
        post->next = cur;

        pre = post->next;
        cur = pre->next;

        if (cur != nullptr)
        {
            post = cur->next;
        }

    }
    return dummyNode->next;
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

    ListNode * res = swapPairs2(preHead->next);
    show(res);
}
