//
// Created by Liu on 2023/7/8.
// Description: 
//

#include<iostream>
using namespace std;

// void removeExtraSpace(string & s){
//     int slow = 0;

//     for(int i = 0; i < s.size(); i++){
//         if(s[i] != ' '){
//             if(slow != 0){
//                 s[slow++] = ' ';
//             }
//             while(i < s.size() && s[i] != ' '){
//                 s[slow++] = s[i++];
//             }
//         }


//     }
//     s.resize(slow);
// }

// void reverse(string & s, int start, int end){
//     int left = start, right = end;

//     while(left < right){
//         char temp = s[left];
//         s[left] = s[right];
//         s[right] = temp;
//         left++;
//         right--;
//     }
// }

// string reverseWords(string s) {
//     removeExtraSpace(s);
//     cout << s << endl;
//     cout << s.size() << endl;

//     reverse(s, 0, s.size()-1);
//     cout << s << endl;
//     cout << s.size() << endl;

//     int left = 0;
//     for(int i = 0; i <= s.size(); ++i){
//         if (s[i] == ' ' || i == s.size())
//         {
//             reverse(s, left, i-1);
//             left = i+1;
//         }

//     }
//     return s;

// }

void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
    for (int i = start, j = end; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
    int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
    for (int i = 0; i < s.size(); ++i) { //
        if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
            if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
            while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow); //slow的大小即为去除多余空格后的大小。
}

string reverseWords(string s) {
    removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
    reverse(s, 0, s.size() - 1);
    int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
            reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
            start = i + 1; //更新下一个单词的开始下标start
        }
    }
    return s;
}

int main(){
    string s;
    getline(cin, s);
    /*
    对于字符数组
    1.使用 getline() 读入整行数据，回车键输入的换行符确定输入结尾。

    调用方法：cin.getline(str, len)

    第一个参数str用来存储输入行的数组名称，第二个参数是要读取的字符数。

    2.使用cin.get(str, len)

    注意：这两种方法都是读取一行输入，直至换行符。

    但是，getline将换行符丢弃，而get()将换行符保留在输入序列里

    对于string类
    使用：getline(cin, str)
    */
    // cin >> s; // C++中这样，字符串中不能有空格
    // cout << s << endl;

    string res = reverseWords(s);
    cout << res;

}
