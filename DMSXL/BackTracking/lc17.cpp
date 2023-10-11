//
// Created by Liu on 2023/7/24.
// Description: 
//

#include<iostream>
#include<vector>
using namespace std;

/*
 * 方法一:
 */
//vector<string> result;
//string s;

//// string类型的数组
//const string letterMap[10]{
//        "", // 0
//        "", // 1
//        "abc", // 2
//        "def", // 3
//        "ghi", // 4
//        "jkl", // 5
//        "mno", // 6
//        "pqrs", // 7
//        "tuv", // 8
//        "wxyz", // 9
//};
//
//// digits的长度代表树的深度
//void backtracking(const string & digits, int index){
//    if(s.size() == digits.size()){
//        result.push_back(s);
//
//        return ;
//    }
//
//    int digit = digits[index] - '0';
//
//    string letters = letterMap[digit];
//
//    for(int i = 0; i < letters.size(); ++i){
//        s.push_back(letters[i]);
//        backtracking(digits, index+1);
//        s.pop_back();
//    }
//
//
//}
//vector<string> letterCombinations(string digits) {
//    if(digits.size() == 0){
//        return result;
//    }
//
//    backtracking(digits, 0);
//    return result;
//}

vector<string> res;
string s;
string getIndex(int i){
    string str ;
    switch(i){ // 每个case语句后面都要加 break!!!
        case 0:
            str = "";
            break;
        case 1:
            str = "";
            break;
        case 2:
            str = "abc";
            break;
        case 3:
            str = "def";
            break;
        case 4:
            str = "ghi";
            break;
        case 5:
            str = "jkl";
            break;
        case 6:
            str = "mno";
            break;
        case 7:
            str = "pqrs";
            break;
        case 8:
            str = "tuv";
            break;
        case 9:
            str = "wxyz";
            break;
        default:
            break;
    }

    return str;
}


void backtracking(string digits, int index){
    if(s.size() == digits.size()){
        res.push_back(s);

        return ;
    }

    cout <<"1: "<< digits[index]-'0' << endl;
    string str = getIndex(digits[index]-'0');
    cout <<"2: " << str << endl;

    for(int i = 0 ; i < str.size(); ++i){
        s.push_back(str[i]);

        backtracking(digits, index+1);

        s.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.size() == 0){
        return res;
    }
    backtracking(digits, 0);
    return res;
}

int main(){

    string digits = "23";

    auto res = letterCombinations(digits);

    for(auto s : res){
        cout << s << endl;
    }
}