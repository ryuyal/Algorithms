
//
// Created by Yao on 2023/9/18.
// Description:     
//

#include <iostream>
#include<queue>
using namespace std;

class MyStack{
public:
    MyStack(){}

    void push(int x){
        que1.push(x);
    }

    // 栈顶元素弹出
    int pop(){
        int size = que1.size()-1;
        for(int i = 0; i < size; ++i){
            que2.push(que1.front());
            que1.pop();
        }

        int res = que1.front();
        que1.pop();
        que1 = que2;

        while(!que2.empty()){
            que2.pop();
        }

        return res;
    }

    // 返回栈顶元素
    int top(){
        return que1.back();
    }

    //
    bool empty(){
        return que1.empty();
    }
private:
    queue<int> que1;
    queue<int> que2;
};

int main() {

}
