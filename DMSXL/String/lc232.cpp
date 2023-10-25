//
// Created by Liu on 2023/7/11.
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
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int res;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        res = s2.top();
        s2.pop();
        return res;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }

  private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
}
