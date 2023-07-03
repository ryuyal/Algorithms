//
// Created by Liu on 2023/7/3.
// Description: 
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;

    ListNode(){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode * n): val(x), next(n){}

};

ListNode * removeElements(ListNode* head, int val) {
    ListNode * newH = new ListNode(0, head);
    ListNode * pre = newH;
    while(pre->next != nullptr){
        if (pre->next->val == val)
        {
            pre->next = pre->next->next;
        }else{
            pre = pre->next;
        }
    }
    return newH->next;
}

void printList(ListNode * head){
    ListNode * cur = head;
    while(cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }

    cout << endl;
}
int main() {
    ListNode * preHead = new ListNode();
    ListNode * pre = preHead;

    int n;
    cout << "Please input the number of elements: " << endl;
    cin >> n;
    while(n > 0){
        int val;
        cin >> val;
        ListNode * temp = new ListNode(val);
        pre->next = temp;
        pre = pre->next;
        --n;
    }

    printList(preHead->next);

    cout << "Please input the element need to be removed:" << endl;
    int target;
    cin >> target;
    ListNode * res = removeElements(preHead->next, target);

    printList(res);
    return 0;
}
