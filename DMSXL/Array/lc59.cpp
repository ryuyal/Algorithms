//
// Created by Liu on 2023/7/3.
// Description: 
//

#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int top = 0, bottom = n-1, left = 0, right = n-1;
    vector<vector<int>> res (n, vector<int>(n));

    int count = 1;
    while(top < bottom){
        for (int i = left; i < right; ++i) {
            res[top][i] = count++;
        }

        for (int i = top; i < bottom; ++i) {
            res[i][right] = count++;
        }

        for (int i = right; i > left; --i) {
            res[bottom][i] = count++;
        }

        for (int i = bottom; i > top; --i) {
            res[i][left] = count++;
        }
        top++;
        bottom--;
        left++;
        right--;
    }

    if (n % 2 == 1){
        res[left][right] = count;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    auto res = generateMatrix(n);

    for(auto v : res){
        for(auto val : v){
            cout << val << " ";
        }
        cout << endl;
    }
}
