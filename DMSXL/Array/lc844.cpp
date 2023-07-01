//
// Created by Liu on 2023/7/2.
// Description: 
//

#include <iostream>
#include<stack>
using namespace std;

bool backspaceCompare(string s, string t) {
    stack<char> stk_s;
    stack<char> stk_t;

    for (int i = 0; i < s.size(); ++i) {
        if (!stk_s.empty() && s[i] == '#'){
            stk_s.pop();
        }else if (s[i] != '#'){
            stk_s.push(s[i]);
        }
    }

    for (int i = 0; i < t.size(); ++i) {
        if (!stk_t.empty() && t[i] == '#'){
            stk_t.pop();
        }else if(t[i] != '#'){
            stk_t.push(t[i]);
        }
    }

    while(!stk_s.empty() && !stk_t.empty()){
        char temp_s = stk_s.top();
        char temp_t = stk_t.top();

        if (temp_s != temp_t){
            return false;
        }
        stk_s.pop();
        stk_t.pop();
    }
    return stk_s.empty() && stk_t.empty();
}

int main() {
    string s;
    cout << "Please input string s: " << endl;
    cin >> s;

    string t;
    cout << "Please input string t: " << endl;
    cin >> t;

    bool res = backspaceCompare(s, t);

    cout << res << endl;
}
