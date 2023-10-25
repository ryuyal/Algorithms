//
// Created by Liu on 2023/7/11.
// Description:
//

#include <iostream>
using namespace std;

void reverse(string &s, int start, int end)
{
    int left = start, right = end;

    while (left < right)
    {
        char ch = s[left];
        s[left] = s[right];
        s[right] = ch;
        left++;
        right--;
    }
}
string reverseLeftWords(string s, int n)
{
    reverse(s, 0, s.size() - 1);

    reverse(s, 0, s.size() - n - 1);
    reverse(s, s.size() - n, s.size() - 1);

    return s;
}

int main()
{

    string s;
    getline(cin, s);

    int n;
    cin >> n;
    string res = reverseLeftWords(s, n);

    cout << res << endl;
}