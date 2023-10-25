//
// Created by Liu on 2023/6/4.
//

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s)
{
    unordered_map<char, int> m{{'(', 1}, {'[', 2}, {'{', 3}, {')', 4}, {']', 5}, {'}', 6}};
    stack<char> st;
    bool istrue = true;
    for (char c : s)
    {
        int flag = m[c];
        if (flag >= 1 && flag <= 3)
            st.push(c);
        else if (!st.empty() && m[st.top()] == flag - 3)
            st.pop();
        else
        {
            istrue = false;
            break;
        }
    }
    if (!st.empty())
        istrue = false;
    return istrue;
}

bool isMatch(char c1, char c2)
{
    if ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}'))
    {
        return true;
    }
    return false;
}
bool isLeft(char c)
{
    if (c == '(' || c == '{' || c == '[')
    {
        return true;
    }
    return false;
}
bool isValid2(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); ++i)
    {
        if (isLeft(s[i]))
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty() || (!isMatch(st.top(), s[i])))
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main()
{

    string s;
    cin >> s;
    bool res = isValid2(s);

    cout << res << endl;
}
