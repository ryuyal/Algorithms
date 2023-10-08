//
// Created by Liu on 2023/7/24.
// Description: 
//

#include<iostream>
#include<vector>
using namespace std;

// 从1-9中找出k个数，这k个数的和为n
vector<vector<int>> result;
vector<int> path;
int sum = 0;

void backtracking(int k, int n, int startIndex, int sum){

    if(path.size() == k){
        if(sum == n){
            result.push_back(path);
        }

        return ;
    }

    for(int i = startIndex; i <= 9 -(k-path.size())+1; ++i){
        sum += i;
        path.push_back(i);
//        if(sum > n){
//            sum -= i;
//            path.pop_back();
//            return ;
//        }
        backtracking(k, n, i+1, sum); // 注意这里是i+1
        path.pop_back(); // 回溯
        sum -= i; // sum也要回溯
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    backtracking(k, n, 1, 0);

    return result;
}

int main(){

}
