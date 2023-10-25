//
// Created by Liu on 2023/7/3.
// Description:
//

#include <iostream>
using namespace std;

class MyLinkedList
{
  public:
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

    MyLinkedList()
    {
        size = 0;
        dummyNode = new ListNode();
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }

        ListNode *cur = dummyNode->next;
        for (int i = 0; i < index; ++i)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *temp = new ListNode(val, dummyNode->next);
        dummyNode->next = temp;
        size++;
    }

    void addAtTail(int val)
    {
        ListNode *pre = dummyNode;
        while (pre->next != nullptr)
        {
            pre = pre->next;
        } // 循环到最后pre指向最后一个节点
        ListNode *temp = new ListNode(val);
        pre->next = temp;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
        {
            return;
        }
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }

        ListNode *pre = dummyNode;
        for (int i = 0; i < index; i++)
        {
            pre = pre->next;
        }

        ListNode *temp = new ListNode(val);
        temp->next = pre->next;
        pre->next = temp;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }

        ListNode *pre = dummyNode;
        for (int i = 0; i < index; i++)
        {
            pre = pre->next;
        }
        ListNode *temp = pre->next;
        pre->next = pre->next->next;
        delete temp;
        temp = nullptr;
        size--;
    }

    void show()
    {
        ListNode *cur = dummyNode->next;
        while (cur != nullptr)
        {
            cout << cur->val << "->";
            cur = cur->next;
        }
        cout << endl;
    }

  private:
    int size;
    ListNode *dummyNode;
};

int main()
{
    MyLinkedList *my = new MyLinkedList();
    my->addAtHead(7);
    my->addAtHead(2);
    my->addAtHead(1);
    my->show();
    my->addAtIndex(3, 0);
    my->show();
}
