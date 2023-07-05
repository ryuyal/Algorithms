//
// Created by Liu on 2023/7/5.
// Description: 
//

#include<iostream>
#include<unordered_map>
using namespace std;

// 判断s2是否包含s1的排列
bool checkInclusion(string s1, string s2) {
    if (s2.length() < s1.length())
    {
        return false;
    }

    unordered_map<char, int> need, window;

    int left = 0, right = 0;
    int cnt = 0;
    for(char ch : s1){
        ++need[ch];
    }

    while(right < s2.length()){
        ++window[s2[right]];

        if (window[s2[right]] <= need[s2[right]])
        {
            cnt++;
        }

        while(left < right && window[s2[left]] > need[s2[left]]){
            --window[s2[left++]];
        }

        if(cnt == s1.length()){
            if (right - left + 1 == s1.length())
            {
                return true;
            }

        }
        right++;
    }
    return false;
}

int main(){
    string s1, s2;

    cin >> s1;
    cin >> s2;

    bool res = checkInclusion(s1, s2);
    cout << res << endl;
}
