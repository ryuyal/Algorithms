
//
// Created by Yao on 2023/10/11.
// Description:
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 方法一 时间复杂度 O(n*2^n)
 * /
/*vector<vector<string>> res;
vector<string> path;

bool isPalindrome(string s){
    int left = 0;
    int right = s.size()-1;
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// startIndex 代表切割位置索引
void backtracking(string & s, int startIndex){
    if(startIndex >= s.size()){
        res.push_back(path);
        return ;
    }

    for(int i = startIndex; i < s.size(); ++i){
        string str = s.substr(startIndex, i-startIndex+1);
        if(isPalindrome(str)){
            path.push_back(str);
        }else{
            continue;
        }

        backtracking(s, i+1);

        path.pop_back();
    }
}

vector<vector<string>> partition(string s){
    backtracking(s, 0);
    return res;
}*/

/*
 * 方法二: 使用动态规划高效计算一个字符串的子串是否为回文串
 */
vector<vector<string>> res;
vector<string> path;
vector<vector<bool>> ispalin;

void isPalindrome(string s)
{
    ispalin.resize(s.size(), vector<bool>(s.size(), false));

    // ispalin[i][j] 代表 s 子串 [i, j] 是否是回文
    for (int right = 0; right < s.size(); ++right)
    {
        for (int left = 0; left <= right; ++left)
        {
            if (s[left] == s[right] && (right - left <= 2 || ispalin[left + 1][right - 1]))
            {
                ispalin[left][right] = true;
            }
        }
    }
}

void backtracking(string &s, int startIndex)
{
    if (startIndex >= s.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = startIndex; i < s.size(); ++i)
    {
        if (ispalin[startIndex][i])
        {
            string str = s.substr(startIndex, i - startIndex + 1);

            path.push_back(str);
        }
        else
        {
            continue;
        }

        backtracking(s, i + 1);

        path.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    isPalindrome(s);

    backtracking(s, 0);
    return res;
}

int main()
{
}
