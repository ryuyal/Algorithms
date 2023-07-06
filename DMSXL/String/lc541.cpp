//
// Created by Liu on 2023/7/6.
// Description: 
//

#include <iostream>

using namespace std;
void reverse(string & s, int left, int right){
    while(left < right){
        char ch = s[left];
        s[left] = s[right];
        s[right] = ch;
        left++;
        right--;
    }
}

string reverseStr(string s, int k) {

    for(int i = 0; i < s.size(); i += 2*k){
        if (i + k <= s.size()){
            reverse(s, i, i + k-1);
        }else{
            reverse(s, i, s.size()-1);
        }
    }

    return s;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    string res = reverseStr(s, k);

    cout << res << endl;
}
