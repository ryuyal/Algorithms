//
// Created by Liu on 2023/7/5.
// Description: 
//

#include<iostream>
#include<unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0;
    unordered_map<char, int> window;
    int res = 0;

    while(right < s.length()){
        ++window[s[right]];

        while(window[s[right]] > 1){
            --window[s[left++]];
        }

        res = max(res, right-left+1);

        right++;
    }

    return res;
}

int main(){
    string s;
    cin >> s;
    int res = lengthOfLongestSubstring(s);
    cout << res << endl;
}