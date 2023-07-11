//
// Created by Liu on 2023/7/11.
// Description: 
//

#include <iostream>
#include<stack>
using namespace std;
bool isMatch(char c1, char c2){
    if ((c1 == '(' && c2 == ')')||(c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}')){
        return true;
    }
    return false;
}
bool isLeft(char c){
    if (c == '(' || c == '{' || c == '['){
        return true;
    }
    return false;
}
bool isValid(string s){
    stack<char> st;

    for (int i = 0; i < s.length(); ++i) {
        if (isLeft(s[i])){
            st.push(s[i]);
        }else{
            if (st.empty() || (!isMatch(st.top(), s[i]))){
                return false;
            }else{
                st.pop();
            }
        }
    }
    return st.empty();
}


int main() {
    string s;
    getline(cin, s);

    bool res = isValid(s);

    cout << res << endl;
}
