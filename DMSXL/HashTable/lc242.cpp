//
// Created by Liu on 2023/7/4.
// Description: 
//

#include<iostream>
#include<unordered_map>
using namespace std;


bool isAnagram(string s, string t) {
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
        }else{
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

int main(){
    string s, t;
    cin >> s;
    cin >> t;

    bool res = isAnagram(s, t);

    cout << res;
}
