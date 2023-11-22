//
// Created by Liu on 2023/7/4.
// Description:
//

#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    unordered_map<char, int> map_s;
    unordered_map<char, int> map_t;

    for (char ch : s)
    {
        map_s[ch]++;
    }

    for (char ch : t)
    {
        map_t[ch]++;
    }

    for (char ch : s)
    {
        if (map_t.count(ch) > 0)
        {
            map_t[ch]--;
        }
        else
        {
            return false;
        }
    }

    for (char ch : t)
    {
        if (map_t[ch] > 0)
        {
            return false;
        }
    }
    return true;
}

// 1122
bool isAnagram2(string s, string t) {
    unordered_map<char, int> sMap;

    for(auto ch : s){
        ++sMap[ch];
    }


    for(auto ch : t){
        if(sMap[ch] <= 0){
            return false;
        }
        --sMap[ch];
        if(sMap[ch] == 0){
            sMap.erase(ch);
        }
    }

    if(sMap.size() == 0){
        return true;
    }
    return false;
}

int main()
{
    string s, t;
    cin >> s;
    cin >> t;

    bool res = isAnagram(s, t);

    cout << res;
}
