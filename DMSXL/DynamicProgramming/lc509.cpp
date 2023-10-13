//
// Created by Liu on 2023/7/28.
// Description: 
//

#include <iostream>

using namespace std;

int fib(int n){
   int n0 = 0;
   int n1 = 1;
   if(n < 2){
       return n;
   }

   int res = 0;
    for (int i = 2; i <= n; ++i) {
        res = n0 + n1;
        n0 = n1;
        n1 = res;
    }

    return res;
}

int fib1(int n) {


    if(n == 0 || n == 1){
        return n;
    }
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int fib2(int n){
    if(n < 2){
        return n;
    }

    return fib(n-1)+fib(n-2);
}

int main() {
    cout << fib(5) << endl;
    cout << fib(3) << endl;
    cout << fib2(5) << endl;
}
