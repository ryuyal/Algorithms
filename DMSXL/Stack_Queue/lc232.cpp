
//
// Created by Yao on 2023/9/7.
// Description:
//

#include <iostream>
#include <stack>

using namespace std;
class MyQueue
{
  public:
    MyQueue()
    {
        size = 0;
    }

    void push(int val)
    {
        stk1.push(val);
        size++;
    }

    int peek()
    {
        if (!stk2.empty())
        {
            return stk2.top();
        }
        else
        {
            while (!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
            return stk2.top();
        }
    }

    int pop()
    {
        int res;
        if (!stk2.empty())
        {
            res = stk2.top();
            stk2.pop();
        }
        else
        {
            while (!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
            res = stk2.top();
            stk2.pop();
        }
        size--;
        return res;
    }

    bool empty()
    {
        return size == 0;
    }

  private:
    stack<int> stk1;
    stack<int> stk2;
    int size;
};

int main()
{
}
