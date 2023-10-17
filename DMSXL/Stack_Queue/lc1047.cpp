
//
// Created by Yao on 2023/9/18.
// Description:     
//

#include <iostream>
#include<stack>
#include<algorithm>
using namespace std;

string removeDuplicates(string s) {

    stack<char> stk;

    for(char ch : s){
        if (stk.empty() || stk.top() != ch){
            stk.push(ch);
        }else{
            stk.pop();
        }
    }

    string res="";
    while(!stk.empty()){
        res+=stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

string removeDuplicates2(string s) {

    string res;

    for(char ch : s){
        if (res.empty() ||res.back() != ch){
            res.push_back(ch);
        }else{
            res.pop_back();
        }
    }

    return res;
}

int main() {
    string s = "abbaca";
    string res = removeDuplicates(s);
    cout<< res << endl;
}
