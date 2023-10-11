
//
// Created by Yao on 2023/10/11.
// Description:     
//

#include <iostream>
#include<vector>
using namespace std;

vector<string> res;

bool isValid(string &s, int start, int end){ // 判断子串合法性
    if(start > end){
        return false;
    }
    if(s[start] == '0' && start != end){
        return false;
    }

    if(end - start > 2){ //
        return false;
    }

    int num = 0;
    for(int i = start; i <= end; ++i){
        if(s[i] > '9' || s[i] < '0'){
            return false;
        }

        num = num * 10 + (s[i]-'0');
        if(num > 255){
            return false;
        }
    }
    return true;
}

void backtracking(string & s, int startIndex, int pointNum){
    if(pointNum == 3){ // 有3个点
        if(isValid(s, startIndex, s.size()-1)){ // 最后
            res.push_back(s);
        }
        return ;
    }

    for(int i = startIndex; i < s.size(); ++i){
        if(isValid(s, startIndex, i)){ //[startIndex, i] 是否合法
            s.insert(s.begin()+i+1, '.');
            pointNum++;

            backtracking(s, i + 2, pointNum);

            pointNum--;
            s.erase(s.begin()+i+1);
        }else{
            break; // 不合法 直接结束本层循环
        }
    }

}

vector<string> restoreIpAddresses(string s){
    if(s.size() < 4 || s.size() >12){
        return res;
    }

    backtracking(s, 0, 0);

    return res;
}

int main() {

}
