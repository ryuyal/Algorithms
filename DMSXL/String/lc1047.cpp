//
// Created by Liu on 2023/7/11.
// Description: 
//

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string removeDuplicates(string s) {
    stack<char> stk;

    for(char ch : s){
        if (stk.empty() || stk.top() != ch)
        {
            stk.push(ch);
        }else{
            stk.pop();
        }
    }

    string res = "";
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main(){

}
