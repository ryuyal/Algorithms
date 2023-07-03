//
// Created by Liu on 2023/7/3.
// Description: 
//

#include <iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> & matrix){
    int m = matrix.size();
    if (m == 0)
    {
        vector<int> res(0);
        return res;
    }

    int n = matrix[0].size();
    vector<int> res(m*n);

    int count = 0;
    int top = 0;
    int bottom = m-1;
    int left = 0;
    int right = n-1;

    while(top < bottom && left < right){
        for (int i = left; i < right; ++i)
        {
            res[count++] = matrix[top][i];
        }

        for (int i = top; i < bottom; ++i)
        {
            res[count++] = matrix[i][right];
        }

        for (int i = right; i > left; --i)
        {
            res[count++] = matrix[bottom][i];
        }

        for (int i = bottom; i > top; --i)
        {
            res[count++] = matrix[i][left];
        }

        left++;
        right--;
        top++;
        bottom--;
    }

    if (top == bottom)
    {
        for (int i = left; i <= right; i++)
        {
            res[count++] = matrix[top][i];
        }
    }else if (left == right){
        for (int i = top; i <= bottom; i++)
        {
            res[count++] = matrix[i][left];
        }
    }

    return res;
}

int main() {
    int m, n;
    cin >> m;
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> res = spiralOrder(matrix);

    for(int val : res){
        cout << val << " ";
    }
}

