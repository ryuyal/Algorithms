//
// Created by Liu on 2023/6/1.
//

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * p1 = l1;
    ListNode * p2 = l2;

    auto * head = new ListNode();
    ListNode * pre = head;
    int flag = 0;

    while(p1 != nullptr || p2 != nullptr){
        int num1 = p1 != nullptr ? p1->val : 0;
        int num2 = p2 != nullptr ? p2->val : 0;

        int sum = num1 + num2 + flag;
        if (sum > 9){
            sum = sum % 10;
            flag = 1;
        }else{
            flag = 0;
        }

        auto * tmp = new ListNode(sum);

        pre->next = tmp;
        pre = pre->next;

        if(p1 != nullptr){
            p1 = p1->next;
        }
        if (p2 != nullptr){
            p2 = p2->next;
        }
    }

    if (flag == 1){
        pre->next = new ListNode(1);
    }

    return head->next;
}

void printList(ListNode * head){
    ListNode * p = head;
    while(p != nullptr){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    ListNode * head1 = new ListNode(2);
    ListNode * h1_2 = new ListNode(4);
    ListNode * h1_3 = new ListNode(3);
    head1->next = h1_2;
    h1_2->next = h1_3;

    ListNode * head2 = new ListNode(5);
    ListNode * h2_2 = new ListNode(6);
    ListNode * h2_3 = new ListNode(4);
    head2->next = h2_2;
    h2_2->next = h2_3;

    ListNode * res = addTwoNumbers(head1, head2);
    printList(res);

}