//
// Created by Liu on 2023/7/11.
// Description:
//

#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
  public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        int size = q1.size();
        for (int i = 0; i < size - 1; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int res = q1.front();
        q1.pop();
        q1 = q2;

        while (!q2.empty())
        {
            q2.pop();
        }

        return res;
    }

    int top()
    {
        return q1.back();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
}