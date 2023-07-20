//
// Created by Liu on 2023/7/20.
// Description: 
//

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;


// dfs深度优先遍历+回溯
void backtracking(int n, int k, int startIndex){
    if(path.size() == k){
        result.push_back(path);
        return ;
    }

    for(int i = startIndex; i <= n; ++i){
        path.push_back(i);
        backtracking(n, k, i+1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k){
    backtracking(n, k, 1);

    return result;
}

int main(){
    int n, k;
    cin >> n;
    cin >> k;


}
