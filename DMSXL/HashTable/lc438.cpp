//
// Created by Liu on 2023/7/5.
// Description:
//

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// // 超出时间限制
// vector<int> findAnagrams(string s, string p) {
//     vector<int> res;
//     if (s.length() < p.length())
//     {
//         return res;
//     }

//     int len = p.length();
//     sort(p.begin(), p.end());
//     for(int i = 0; i <= s.length()-len; ++i){
//         string temp = s.substr(i, len);
//         sort(temp.begin(), temp.end());
//         if (temp == p)
//         {
//             res.push_back(i);
//         }

//     }
//     return res;
// }

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    if (s.length() < p.length())
    {
        return res;
    }

    unordered_map<char, int> need, window;
    for (char ch : p)
    {
        ++need[ch];
    }

    int left = 0, right = 0;
    int cnt = 0;
    while (right < s.length())
    {
        ++window[s[right]];
        if (window[s[right]] <= need[s[right]])
        {
            ++cnt;
        }

        while (left < right && window[s[left]] > need[s[left]])
        {
            --window[s[left++]];
        }

        if (cnt == p.length())
        {
            if (right - left + 1 == p.length())
            {
                res.push_back(left);
            }
        }
        ++right;
    }
}

int main()
{
    string s, p;
    cin >> s;
    cin >> p;

    auto res = findAnagrams(s, p);
    for (auto v : res)
    {
        cout << v << endl;
    }
}