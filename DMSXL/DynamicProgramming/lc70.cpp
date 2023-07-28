//
// Created by Liu on 2023/7/28.
// Description: 
//

#include <iostream>

using namespace std;

int climbStairs(int n) {
    if(n <= 2){
        return n;
    }

    int res = 0;
    int n1 = 1;
    int n2 = 2;
    for(int i = 3; i <= n; ++i){
        res = n1 + n2;
        n1 = n2;
        n2 = res;
    }

    return res;
}

//// 超时
//int climbStairs2(int n) {
//    if(n <= 2){
//        return n;
//    }
//
//    return climbStairs(n-2) + climbStairs(n-1);
//
//}

int main() {
    cout << climbStairs(3) << endl;
}
