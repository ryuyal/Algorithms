//
// Created by Liu on 2023/6/30.
// Description: 
//

#include <iostream>

using namespace std;

bool isPerfectSquare(int num){
    if(num == 0 || num == 1){
        return true;
    }
    if (num == 2){
        return false;
    }

    long left = -1;
    long right = num;

    while(left + 1 != right){
        long mid = left + (right - left) / 2;
        if (num / mid == mid && num % mid == 0){
            return true;
        }else if(num / mid < mid){
            right = mid;
        }else{
            left = mid;
        }
    }
    return false;
}

int main() {
    int num;
    cin >> num;

    bool res = isPerfecSquare(num);

    cout << res;
}
