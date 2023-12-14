
//
// Created by Yao on 2023/12/14.
// Description:
//

/*
 * N皇后
 */
#include <iostream>
#include<vector>

using namespace std;

vector<vector<string>> res;

bool isValid(int row, int col, int n, vector<string> & chessboard){
    for(int i = 0; i < row; ++i){
        if(chessboard[i][col] == 'Q'){
            return false;
        }
    }

    for(int i = row-1, j = col-1; i >=0 && j >=0; --i, --j){
        if(chessboard[i][j] == 'Q'){
            return false;
        }
    }

    for(int i = row-1, j = col+1; i >=0 && j < n; --i, ++j){
        if(chessboard[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}
void backtracking(int row, int n, vector<string> &chessboard){
    if(row == n){
        res.push_back(chessboard);

        return ;
    }

    for(int col = 0; col < n; ++col){
        if(isValid(row, col, n, chessboard)){
            chessboard[row][col] = 'Q';
            backtracking(row+1, n, chessboard);
            chessboard[row][col] = '.';
        }
    }
}


vector<vector<string>> solveNQueens(int n) {
    vector<string> chessboard(n, string(n, '.'));

    backtracking(0, n, chessboard);

    return res;
}
int main()
{
    int n = 3;
    auto res = solveNQueens(n);

    for(auto vec : res){
        for(string s : vec){
            cout << s << endl;
        }

        cout << endl;
    }

}
