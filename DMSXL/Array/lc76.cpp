//
// Created by Liu on 2023/7/2.
// Description:
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// string minWindow(string s, string t) {
//     unordered_map<char, int> tmap, smap;
//     int left = 0, correct = 0;
//     string res = s + "initialize a max string";
//     // 对于t制作字符出现数的字典
//     for (auto item : t)
//         ++tmap[item];
//
//     for (int right = 0; right < s.size(); ++right) {
//         // smap维护的是当前窗口内的字符出现数的字典
//         ++smap[s[right]];
//         //
//         当前right对应s的字符是在t中出现的，并且数量上还没有达到冗余，是一次有效添加
//         if (tmap[s[right]] >= smap[s[right]])
//             ++correct;
//         // 字符串最短是空串 && 如果left对应的字符是冗余，那么进行右移删除
//         while (left < right && smap[s[left]] > tmap[s[left]])
//             --smap[s[left++]];
//         if (correct == t.size()){
//             // 窗口内已经满足t串的所有字符
//             if (right - left + 1 < res.size())
//                 res = s.substr(left, right - left + 1);
//         }
//
//     }
//     return res == s + "initialize a max string" ? "" : res;
// }
string minWindow(string s, string t)
{
    unordered_map<char, int> hs, ht;

    for (auto c : t)
    {
        ++ht[c];
    }

    int left = 0;
    int right = 0;
    string res = s + "initialize a max string";
    ;

    int cnt = 0;
    for (; right < s.size(); ++right)
    {
        ++hs[s[right]];

        // 当前right对应s的字符是在t中出现的，并且数量上还没有达到冗余，是一次有效添加
        if (hs[s[right]] <= ht[s[right]])
        {          // 说明当前新加入的字符s[right]是必需的
            ++cnt; // 新加入的字符s[right]必需，则cnt++。
        }

        // 注意！！！
        // 这里收缩完窗口时，最坏的情况是hs[left] == ht[s[left]]
        // 所以不需要对cnt进行额外处理
        while (left < right && hs[s[left]] > ht[s[left]])
        {                    // 满足条件
            --hs[s[left++]]; // 压缩窗口
        }

        if (cnt == t.size())
        {
            // 窗口内已经满足t串的所有字符
            if (right - left + 1 < res.size())
            {
                res = s.substr(left, right - left + 1);
            }
        }
    }

    return res == s + "initialize a max string" ? "" : res;
}

int main()
{
    string s, t;
    cout << "Please input string s: " << endl;
    cin >> s;

    cout << "Please input string t: " << endl;
    cin >> t;

    string res = minWindow(s, t);

    cout << res;
}
