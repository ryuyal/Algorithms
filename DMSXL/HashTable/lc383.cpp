//
// Created by Liu on 2023/7/4.
// Description:
//

#include <iostream>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> mMap;
    for (char ch : magazine)
    {
        mMap[ch]++;
    }

    for (char ch : ransomNote)
    {
        if (mMap[ch] > 0)
        {
            mMap[ch]--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string ran;
    string mag;

    cin >> ran;
    cin >> mag;

    bool res = canConstruct(ran, mag);
    cout << res;
}
