//
// Created by Liu on 2023/7/5.
// Description: 
//

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 超出时间限制
// bool isAnagram(string s, string t){
//     if (s.length() != t.length())
//     {
//         return false;
//     }

//     unordered_map<char, int> sMap;
//     unordered_map<char, int> tMap;
//     for(char ch : s){
//         sMap[ch]++;
//     }
//     for(char ch : t){
//         if(sMap[ch] > 0){
//             sMap[ch]--;
//         }else{
//             return false;
//         }
//     }
//     for(char ch : s){
//         if (sMap[ch] != 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     vector<vector<string>> res;
//     int len = strs.size();

//     vector<bool> flag(len, 0);


//     // bool flag[10] = {1}; // 只有数组第一个元素为1
//     for(int i = 0; i < strs.size(); ++i){
//         if (flag[i])
//         {
//             continue;
//         }

//         flag[i] = true;

//         vector<string> temp;
//         temp.push_back(strs[i]);
//         for (int j = i+1; j < strs.size(); ++j)
//         {
//             if (flag[j])
//             {
//                 continue;
//             }

//             if (isAnagram(strs[i], strs[j]))
//             {
//                 flag[j] = true;
//                 temp.push_back(strs[j]);
//             }
//         }
//         res.push_back(temp);

//     }
//     return res;

// }

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> strMap;

    for (auto str : strs)
    {
        string temp = str;
        sort(str.begin(), str.end());
        strMap[str].push_back(temp);
    }

    vector<vector<string>> res;
    for(auto v : strMap){
        res.push_back(v.second);
    }

    return res;

}

int main(){
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    auto res = groupAnagrams(strs);

    for(auto v : res){
        cout << "[ " ;
        for(auto s : v){
            cout << s << " ";
        }
        cout << "]" << endl;
    }
}