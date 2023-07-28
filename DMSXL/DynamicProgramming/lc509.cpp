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

int fib2(int n){
    if(n < 2){
        return n;
    }

    return fib(n-1)+fib(n-2);
}

int main() {
    cout << fib(5) << endl;
    cout << fib2(5) << endl;
}
